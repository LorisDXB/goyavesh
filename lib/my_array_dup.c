/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-alexis.seymour
** File description:
** my_array_dup.c
*/

#include "my.h"

char **my_array_dup(char **env)
{
    char **new_env = malloc(sizeof(char *) * (my_arrlen(env) + 2));
    int i = 0;

    for (i = 0; env[i] != NULL; i++) {
        new_env[i] = my_strcpy(new_env[i], env[i]);
    }
    new_env[i + 1] = NULL;
    return new_env;
}
