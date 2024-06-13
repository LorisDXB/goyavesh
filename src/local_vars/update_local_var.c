/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** update_local_var.c
*/

#include "../../include/goyave.h"

static char *sub_change_var(char *to_change, char *value)
{
    if (value == NULL)
        to_change = value;
    else
        to_change = strdup(value);
    return to_change;
}

static dict_t *change_var(dict_t *local_vars, char *key, char *value)
{
    dict_t *tmp = local_vars;

    while (tmp != NULL) {
        if (strcmp(tmp->key, key) == 0)
            tmp->value = sub_change_var(tmp->value, value);
        tmp = tmp->next;
    }
    return local_vars;
}

dict_t *update_local_var_comp(dict_t *local_vars, char **params, int *i)
{
    local_vars = change_var(local_vars, get_var_name(params[*i]),
        get_var_value(params[*i]));
    *i += 1;
    return local_vars;
}

dict_t *update_local_var(dict_t *local_vars, char **params, int *i)
{
    char *key = strdup(params[*i]);
    char *value;

    if (params[*i + 1] == NULL || strcmp(params[*i + 1], "=") != 0) {
        value = NULL;
        *i += 1;
    } else {
        if (params[*i + 2] != NULL) {
            value = strdup(params[*i + 2]);
            *i += 3;
        } else {
            value = NULL;
            *i += 2;
        }
    }
    local_vars = change_var(local_vars, key, value);
    return local_vars;
}
