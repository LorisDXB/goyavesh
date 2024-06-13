/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-alexis.seymour
** File description:
** unsetenv.c
*/

#include "goyave.h"

int unset_env(char ***env, char *params)
{
    int index_env = find_index_env(*env, params);
    char **new_env = NULL;

    if (index_env == -1)
        return 0;
    new_env = my_array_sup_dup(*env, index_env);
    *env = new_env;
    return 0;
}

int unset_env_hub(char ***env, char **params)
{
    int i = 1;

    while (params[i] != NULL) {
        unset_env(env, params[i]);
        i++;
    }
    return 0;
}
