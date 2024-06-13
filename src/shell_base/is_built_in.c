/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-keyvan.goddard
** File description:
** is_built_in.c
*/
#include "goyave.h"

static int next2(char *str)
{
    if (strcmp(str, "unset") == 0)
        return 1;
    if (strcmp(str, "unalias") == 0)
        return 1;
    if (strcmp(str, "which") == 0)
        return 1;
    if (strcmp(str, "where") == 0)
        return 1;
    return 0;
}

static int next(char *str)
{
    if (strcmp(str, "history") == 0)
        return 1;
    if (strcmp(str, "exit") == 0)
        return 1;
    if (strcmp(str, "alias") == 0)
        return 1;
    if (strcmp(str, "set") == 0)
        return 1;
    if (strcmp(str, "jobs") == 0)
        return 1;
    if (strcmp(str, "bg") == 0)
        return 1;
    if (strcmp(str, "fg") == 0)
        return 1;
    if (strcmp(str, "echo") == 0)
        return 1;
    return next2(str);
}

int is_built_in(char *str)
{
    if (!str)
        return 0;
    str = remove_first_space_from_str(str);
    if (strcmp(str, "cd") == 0) {
        return 1;
    }
    if (strcmp(str, "env") == 0) {
        return 1;
    }
    if (strcmp(str, "setenv") == 0) {
        return 1;
    }
    if (strcmp(str, "unsetenv") == 0) {
        return 1;
    }
    return next(str);
}
