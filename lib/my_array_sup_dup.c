/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-alexis.seymour
** File description:
** my_array_dup.c
*/

#include "my.h"

char **my_array_sup_dup(char **env, int index)
{
    char **new_env = malloc(sizeof(char *) * (my_arrlen(env) + 1));
    int i = 0;
    int k = 0;

    while (env[i] != NULL) {
        if (index == i) {
            i++;
        }
        new_env[k] = my_strcpy(new_env[k], env[i]);
        k++;
        if (env[i] == NULL)
            break;
        i++;
    }
    new_env[k] = NULL;
    return new_env;
}
