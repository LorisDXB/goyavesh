/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** exclamation_mark.c
*/
#include "goyave.h"

static int my_comp(char *s1, char *s2, int n)
{
    for (int i = 0; s1[i] && s2[i] && i < n; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}

static void display_cmd(char **history, int start, int i, int print_error)
{
    if (print_error)
        my_printf("%s\n", history[i] + start);
}

static void find_command_case(char **history, char **str, int b,
    int print_error)
{
    int start = 0;

    if (my_arrlen(history) < 2) {
        if (print_error)
            my_printf("No history\n");
        return;
    }
    for (int i = 0; history[i]; i++) {
        start = get_cmd_start(history[i]);
        if (my_comp(str[b] + 1, history[i] + start, strlen(str[b]) - 1)) {
            free(str[b]);
            str[b] = strdup(history[i] + start);
            display_cmd(history, start, i, print_error);
            break;
        }
    }
}

static char **previous_cmd_case(char **str, char **history, int b)
{
    int start = 0;

    free(str[b]);
    start = get_cmd_start(history[my_arrlen(history) - 2]);
    str[b] = strdup(history[my_arrlen(history) - 1] + start);
    my_printf("%s\n", history[my_arrlen(history) - 1] + start);
    return str;
}

static char *cmd_number(char *str, char **history, int nb, int print_error)
{
    if (my_arrlen(history) < 2) {
        if (print_error)
            my_printf("No history\n");
        return str;
    }
    if (nb > my_arrlen(history) - 1 || nb == 0 ||
    (nb < 0 && nb * -1 > my_arrlen(history) - 1)) {
        if (print_error)
            my_printf("%d: Event not found.\n", nb);
        return str;
    }
    free(str);
    if (nb < 0)
        str = strdup(history[my_arrlen(history) + nb] +
        get_cmd_start(history[my_arrlen(history) + nb]));
    else
        str = strdup(history[nb - 1] + get_cmd_start(history[nb - 1]));
    return str;
}

static char **error_print(char **history, char **str, int print_error, int b)
{
    if (my_arrlen(history) < 2) {
        if (print_error)
            my_printf("No history\n");
        return str;
    } else {
        return previous_cmd_case(str, history, b);
    }
}

static char **condition(char **str, int b, char **history, int print_error)
{
    int nb = 0;

    if (!history)
        return str;
    if (str[b][1] == '!') {
        error_print(history, str, print_error, b);
    }
    nb = atoi(str[b] + 1);
    if (nb == 0) {
        find_command_case(history, str, b, print_error);
    } else {
        str[b] = cmd_number(str[b], history, nb, print_error);
    }
    return str;
}

char **compare_both_history(char **str, int b, repo_t *repo, int print_error)
{
    char **history = history_to_array(repo);
    char **ret = NULL;

    if (str[b][0] == '!') {
        if (strlen(str[b]) >= 2) {
            ret = condition(str, b, history, print_error);
            free_array(history);
            return ret;
        }
    }
    if (history)
        free_array(history);
    return str;
}
