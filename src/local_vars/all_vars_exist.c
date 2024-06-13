/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** all_var_exist.c
*/

#include "../../include/goyave.h"

static int var_exists(char *name, dict_t *local_vars)
{
    dict_t *tmp = local_vars;

    while (tmp) {
        if (strcmp(tmp->key, name) == 0)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

static int env_var_exists(char *name, char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], name, my_strlen(name)) == 0)
            return 1;
    }
    return 0;
}

static int sub_all_vars_exist(char **env, dict_t *local_vars,
    char *buffer, int i)
{
    char *name = NULL;

    if (buffer[i] == '$') {
        name = find_var_name(buffer, &i);
        if (var_exists(name, local_vars) == 0
        && env_var_exists(name, env) == 0) {
            printf("%s: Undefined variable.\n", name);
            free(name);
            return 1;
        }
        free(name);
    }
    return 0;
}

int all_vars_exist(char **env, dict_t *local_vars, char *buffer)
{
    for (int i = 4; i < my_strlen(buffer); i++) {
        if (sub_all_vars_exist(env, local_vars, buffer, i) == 1)
            return 1;
    }
    return 0;
}
