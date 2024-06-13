/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** alias_command.c
*/

#include "../../include/goyave.h"

static int get_len_value(char **params)
{
    int count = 0;

    count += strlen(params[2]);
    for (int i = 3; params[i] != NULL; i++) {
        count++;
        count += strlen(params[i]);
    }
    return count;
}

static dict_t *update_alias(dict_t *alias, char **params)
{
    dict_t *tmp = alias;
    char *value = malloc(sizeof(char) * (get_len_value(params) + 1));

    value[0] = '\0';
    strcat(value, params[2]);
    if (len_array(params) > 3) {
        for (int i = 3; params[i] != NULL; i++) {
            strcat(value, " ");
            strcat(value, params[i]);
        }
    }
    while (tmp) {
        if (strcmp(tmp->key, params[1]) == 0)
            tmp->value = strdup(value);
        tmp = tmp->next;
    }
    return alias;
}

static dict_t *add_alias(dict_t *alias, char **params)
{
    char *key = strdup(params[1]);
    char *value = malloc(sizeof(char) * (get_len_value(params) + 1));

    value[0] = '\0';
    strcat(value, params[2]);
    if (len_array(params) > 3) {
        for (int i = 3; params[i] != NULL; i++) {
            strcat(value, " ");
            strcat(value, params[i]);
        }
    }
    alias = push_to_list(alias, key, value);
    return alias;
}

int alias_command(repo_t *repo, char **params)
{
    if (len_array(params) == 1 || (len_array(params) == 2
        && strcmp(params[1], "-p") == 0))
        print_alias(repo->alias);
    if (len_array(params) > 2) {
        if (already_in(repo->alias, params[1]) == 0)
            repo->alias = add_alias(repo->alias, params);
        if (already_in(repo->alias, params[1]) == 1)
            repo->alias = update_alias(repo->alias, params);
    }
    return 0;
}
