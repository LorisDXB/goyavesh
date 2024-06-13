/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** print_alias.c
*/

#include "../../include/goyave.h"

static int multiple(char *value)
{
    for (int i = 0; value[i] != '\0'; i++) {
        if (value[i] == ' ')
            return 1;
    }
    return 0;
}

void print_alias(dict_t *alias)
{
    dict_t *tmp = alias;

    while (tmp != NULL) {
        printf("%s\t", tmp->key);
        if (multiple(tmp->value) == 1)
            printf("(%s)\n", tmp->value);
        if (multiple(tmp->value) == 0)
            printf("%s\n", tmp->value);
        tmp = tmp->next;
    }
}
