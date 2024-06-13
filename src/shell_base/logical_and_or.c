/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** logical_and.c
*/
#include "goyave.h"



static int get_first_and(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == '&' && str[i + 1] == '&') {
            return i;
        }
    }
    return i;
}

static int get_first_or(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == '|' && str[i + 1] == '|')
            return i;
    }
    return i;
}

static char **split_and(char *str)
{
    char **tab = calloc(sizeof(char *), 3);

    tab[0] = my_strdup_start_end(str, 0, get_first_and(str));
    if (get_first_and(str) == my_strlen(str))
        tab[1] = my_strdup_start_end(str, get_first_and(str), my_strlen(str));
    else
        tab[1] = my_strdup_start_end(str, get_first_and(str) + 2,
        my_strlen(str));
    tab[2] = NULL;
    return tab;
}

static char **split_or(char *str)
{
    char **tab = calloc(sizeof(char *), 3);

    tab[0] = my_strdup_start_end(str, 0, get_first_or(str));
    if (get_first_or(str) == my_strlen(str))
        tab[1] = my_strdup_start_end(str, get_first_or(str), my_strlen(str));
    else
        tab[1] = my_strdup_start_end(str, get_first_or(str) + 2,
        my_strlen(str));
    tab[2] = NULL;
    return tab;
}

int execute_logical_and(repo_t *repo, char *buf)
{
    char **sep = split_and(buf);
    int ret1 = 0;
    int ret2 = 0;

    if (strlen(buf) == 0) {
        free_array(sep);
        return 0;
    }
    if (search_and(buf, 0, my_strlen(buf)) == -1) {
        free_array(sep);
        return manage_redirections(repo, buf);
    }
    ret1 = execute_logical_and(repo, sep[0]);
    if (ret1 != 0) {
        free_array(sep);
        return ret1;
    }
    ret2 = execute_logical_and(repo, sep[1]);
    free_array(sep);
    return ret2;
}

static int breaker(char *buf, char **sep)
{
    if (strlen(buf) == 0) {
        free_array(sep);
        return 1;
    }
    return 0;
}

static void recc_or(repo_t *repo, char **sep)
{
    execute_logical_or(repo, sep[0]);
    execute_logical_or(repo, sep[1]);
    free_array(sep);
}

int execute_logical_or(repo_t *repo, char *buf)
{
    char **sep = split_or(buf);
    static int tot_cmd = 0;
    static int tot_cmd_failled = 0;
    int ret1 = 0;

    if (breaker(buf, sep))
        return 0;
    if (search_or(buf, 0, my_strlen(buf)) == -1) {
        tot_cmd++;
        ret1 = execute_logical_and(repo, buf);
        if (ret1 != 0)
            tot_cmd_failled++;
        free_array(sep);
        return ret1;
    }
    recc_or(repo, sep);
    if (tot_cmd == tot_cmd_failled)
        return 1;
    return 0;
}
