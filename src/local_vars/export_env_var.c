/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** export_env_var.c
*/

#include "goyave.h"

static int verif_export(char *command)
{
    char *name = get_var_name(command);

    if (command[0] > 47 && command[0] < 58) {
        printf("export: not an identifier: %s\n", name);
        free(name);
        return 1;
    }
    return 0;
}

static int add_or_change_export(repo_t *repo, char *name, char *value)
{
    int index_env;
    char **new_env = NULL;
    int last_line_env = my_arrlen(*repo->env);

    if (value == NULL)
        value = my_strcpy(value, "\0");
    index_env = find_index_env(*repo->env, name);
    if (index_env == -1) {
        new_env = my_array_dup(*repo->env);
        *repo->env = new_env;
        (*repo->env)[last_line_env] = my_strcpy((*repo->env)
            [last_line_env], my_strcat(name, my_strcat("=", value)));
    } else
        (*repo->env)[index_env] = my_strcpy((*repo->env)[last_line_env],
        my_strcat(name, my_strcat("=", value)));
    return 0;
}

int export_env_var(repo_t *repo, char **params)
{
    char *name = NULL;
    char *value = NULL;

    for (int i = 1; params[i] != NULL; i++) {
        if (verif_export(params[i]) == 1)
            return 1;
        name = get_var_name(params[i]);
        value = get_var_value(params[i]);
        add_or_change_export(repo, name, value);
        free(name);
        free(value);
    }
    return 0;
}
