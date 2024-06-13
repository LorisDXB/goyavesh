/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** is_alias.c
*/

#include "../../include/goyave.h"

char *is_alias(dict_t *alias, char *command)
{
    dict_t *tmp = alias;

    while (tmp) {
        if (strcmp(tmp->key, command) == 0)
            return tmp->value;
        tmp = tmp->next;
    }
    return NULL;
}
