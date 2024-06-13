/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** add_local_var.c
*/

#include "../../include/goyave.h"

dict_t *push_to_list(dict_t *dict, char *key, char *value)
{
    dict_t *new_var = malloc(sizeof(dict_t));

    new_var->key = key;
    new_var->value = value;
    new_var->next = dict;
    dict = new_var;
    return dict;
}

dict_t *add_local_var_comp(dict_t *local_vars, char **params, int *i)
{
    local_vars = push_to_list(local_vars, get_var_name(params[*i]),
        get_var_value(params[*i]));
    *i += 1;
    return local_vars;
}

dict_t *add_local_var(dict_t *local_vars, char **params, int *i)
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
    local_vars = push_to_list(local_vars, key, value);
    return local_vars;
}
