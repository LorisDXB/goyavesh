/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** set_local_var.c
*/

#include "../../include/goyave.h"
#include <stdio.h>

int already_in(dict_t *dict, char *param)
{
    dict_t *tmp = dict;

    while (tmp != NULL) {
        if ((complete_dec(param) == 1
            && strcmp(tmp->key, get_var_name(param)) == 0)
            || (complete_dec(param) == 0 && strcmp(tmp->key, param) == 0))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

static dict_t *choose_func(dict_t *local_vars, char **params, int *i)
{
    if (already_in(local_vars, params[*i]) == 1) {
        if (complete_dec(params[*i]) == 1)
            return update_local_var_comp(local_vars, params, i);
        else
            return update_local_var(local_vars, params, i);
    }
    if (already_in(local_vars, params[*i]) == 0) {
        if (complete_dec(params[*i]) == 1)
            return add_local_var_comp(local_vars, params, i);
        else
            return add_local_var(local_vars, params, i);
    }
    return local_vars;
}

int set_local_var(repo_t *repo, char **params)
{
    int i = 1;

    if (strcmp(params[0], "set") != 0 && strcmp(params[0], "local") != 0)
        i = 0;
    if (correct_set(params) == 84)
        return 1;
    while (params[i] != NULL)
        repo->local_vars = choose_func(repo->local_vars, params, &i);
    return 0;
}
