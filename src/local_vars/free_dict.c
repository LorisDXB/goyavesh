/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** free_dict.c
*/

#include "../../include/goyave.h"

void free_dict(dict_t *local_vars)
{
    dict_t *tmp = local_vars;

    while (tmp != NULL) {
        free(tmp->key);
        if (tmp->value)
            free(tmp->value);
        tmp = tmp->next;
    }
}
