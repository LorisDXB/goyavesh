/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** unalias_command.c
*/

#include "../../include/goyave.h"

static dict_t *delete_alias(dict_t *alias, char *key)
{
    dict_t *tmp = alias;
    dict_t *prev;

    if (tmp != NULL && strcmp(tmp->key, key) == 0) {
        alias = tmp->next;
        return alias;
    }
    while (tmp != NULL && strcmp(tmp->key, key) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return alias;
    prev->next = tmp->next;
    return alias;
}

int unalias_command(repo_t *repo, char **params)
{
    if (len_array(params) == 1) {
        write(2, "unalias: Too few arguments.\n", 28);
        return 1;
    }
    for (int i = 1; params[i] != NULL; i++)
        repo->alias = delete_alias(repo->alias, params[i]);
    return 0;
}
