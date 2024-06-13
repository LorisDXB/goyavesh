/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-keyvan.goddard
** File description:
** remove_space_from_str.c
*/
#include "goyave.h"

static int count_space(char *str, int i)
{
    int count = 0;

    while (str[i] && str[i] == ' ') {
        count++;
        i++;
    }
    return count;
}

static char *change_expression(char *str, int i, int nb_space)
{
    while (str[i] && str[i + nb_space]) {
        str[i] = str[i + nb_space];
        i++;
    }
    return str;
}

static int count_tot_space(char *str)
{
    int i = 0;
    int count = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count;
}

char *remove_space_from_str(char *str)
{
    int nb_space_in_str = count_tot_space(str);
    int nb_space = 0;
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            nb_space = count_space(str, i);
            str = change_expression(str, i, nb_space);
        }
        if (i == my_strlen(str) - nb_space_in_str) {
            break;
        }
    }
    while (str[i + 1]) {
        str[i] = '\0';
        i++;
    }
    return str;
}

char *remove_first_space_from_str(char *str)
{
    int nb_space = 0;
    int i = 0;

    nb_space = count_space(str, i);
    str = change_expression(str, i, nb_space);
    i = my_strlen(str) - nb_space;
    str[i] = '\0';
    return str;
}

char *remove_last_space_from_str(char *str)
{
    int i = 0;

    for (i = my_strlen(str) - 1; i >= 0 && str[i] == ' '; i--) {
    }
    str[i + 1] = '\0';
    return str;
}

char *remove_line_break(char *str)
{
    int i = 0;

    for (i = my_strlen(str) - 1; i >= 0 && str[i] == '\n'; i--) {
    }
    str[i + 1] = '\0';
    return str;
}
