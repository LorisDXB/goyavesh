/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-keyvan.goddard
** File description:
** ast_search_sep.c
*/
#include "goyave.h"


int search_sep(char *str, int start, int end)
{
    int i = start;

    for (i = start; str[i] && i < end; i++) {
        if (str[i] == ';') {
            return i;
        }
    }
    return -1;
}

int search_pipe(char *str, int start, int end)
{
    int i = start;

    for (i = start; str[i] && i < end; i++) {
        if (str[i] == '|' && str[i + 1] != '|') {
            return i;
        }
    }
    return -1;
}

int search_red(char *str, int start, int end)
{
    int i = start;

    for (i = start; str[i] && i < end; i++) {
        if (str[i] == '<' || str[i] == '>') {
            return i;
        }
    }
    return -1;
}

int search_and(char *str, int start, int end)
{
    int i = start;

    for (i = start; str[i] && i < end; i++) {
        if (str[i] == '&' && str[i + 1] == '&') {
            return i;
        }
    }
    return -1;
}

int search_or(char *str, int start, int end)
{
    int i = start;

    for (i = start; str[i] && i < end; i++) {
        if (str[i] == '|' && str[i + 1] == '|') {
            return i;
        }
    }
    return -1;
}
