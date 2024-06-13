/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** unset_local_var.c
*/

#include "../../include/goyave.h"

static dict_t *delete_var(dict_t *local_vars, char *key)
{
    dict_t *tmp = local_vars;
    dict_t *prev;

    if (tmp != NULL && strcmp(tmp->key, key) == 0) {
        local_vars = tmp->next;
        return local_vars;
    }
    while (tmp != NULL && strcmp(tmp->key, key) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return local_vars;
    prev->next = tmp->next;
    return local_vars;
}

int unset_local_var(repo_t *repo, char **params)
{
    if (len_array(params) == 1) {
        write(2, "unset: Too few arguments.\n", 26);
        return 1;
    }
    for (int i = 1; params[i] != NULL; i++)
        repo->local_vars = delete_var(repo->local_vars, params[i]);
    return 0;
}
