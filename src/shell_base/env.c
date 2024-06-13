/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-alexis.seymour
** File description:
** env.c
*/

#include "goyave.h"

int find_index_env(char **env, char *params)
{
    int i = 0;
    int k = 0;

    for (i = 0; env[i] != NULL; i++) {
        k = 0;
        for (; params[k] == env[i][k] && params[k] != '\0'; k++);
        if (k == my_strlen(params)) {
            return i;
        }
    }
    return -1;
}

int verif_alpha_for_setenv(char *params, int *exit)
{
    int k = 0;

    if (isalpha(params[k]) == 0 && params[k] != '_') {
        my_printf("setenv: Variable name must begin with a letter.\n");
        *exit = 1;
        return -1;
    }
    while (params[k] != '\0') {
        if (isalnum(params[k]) == 0 && params[k] != '_')
            *exit = 1;
        k++;
    }
    if (*exit == 1) {
        my_printf("setenv: Variable name must contain");
        my_printf(" alphanumeric characters.\n");
        return -1;
    }
    return 1;
}

int verif_imput(char **params)
{
    int exit = 0;

    if (my_arrlen(params) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    if (verif_alpha_for_setenv(params[1], &exit) == -1)
        return 1;
    return exit;
}

static void change_params(char **params, char ***env)
{
    int index_env = find_index_env(*env, params[1]);
    int last_line_env = my_arrlen(*env);
    char **new_env = NULL;

    if (index_env == -1) {
        new_env = my_array_dup(*env);
        *env = new_env;
        (*env)[last_line_env] = my_strcpy((*env)[last_line_env],
        my_strcat(params[1], my_strcat("=", params[2])));
    } else {
        (*env)[index_env] = my_strcpy((*env)[last_line_env],
        my_strcat(params[1], my_strcat("=", params[2])));
    }
}

int set_env(char ***env, char **params)
{
    int exit = verif_imput(params);

    if (exit != 0)
        return exit;
    if (params[2] == NULL) {
        params[2] = my_strdup("");
    }
    change_params(params, env);
    if (strcmp(params[2], "") == 0)
        params[2] = NULL;
    return 0;
}

int print_env(char **env)
{
    my_show_word_array(env);
    return 0;
}
