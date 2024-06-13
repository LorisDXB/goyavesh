/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** which_where.c
*/
#include "goyave.h"


static void check_which2(char *cmd, repo_t *repo, int *ret)
{
    dict_t *elm = repo->alias;
    int disp = 0;
    char **path = check_path((repo->env));
    char *tab[1] = {cmd};

    while (elm != NULL) {
        if (strcmp(repo->alias->key, cmd) == 0) {
            my_printf("%s:\taliased to %s %s\n", cmd, cmd, elm->next);
            disp = 1;
        }
        elm = elm->next;
    }
    if (!disp) {
        if (!get_file_to_path(tab, path)) {
            my_printf("%s: Command not found.\n", tab[0]);
            *ret = 1;
        } else {
            my_printf("%s\n", tab[0]);
        }
    }
}

static void check_where2(char *cmd, repo_t *repo, int *ret)
{
    dict_t *elm = repo->alias;
    char **path = check_path((repo->env));
    char *tab[1] = {cmd};

    while (elm != NULL) {
        if (strcmp(repo->alias->key, cmd) == 0) {
            my_printf("%s:\taliased to %s %s\n", cmd, cmd, elm->next);
        }
        elm = elm->next;
    }
    if (!get_file_to_path(tab, path)) {
        my_printf("%s: Command not found.\n", tab[0]);
        *ret = 1;
    } else {
        my_printf("%s\n", tab[0]);
    }
}

int check_which(repo_t *repo, char **params)
{
    int ret = 0;

    for (int i = 1; params[i]; i++) {
        if (is_built_in(params[i])) {
            my_printf("%s: shell built-in command.\n", params[i]);
        } else {
            check_which2(params[i], repo, &ret);
        }
    }
    return ret;
}

int check_where(repo_t *repo, char **params)
{
    int ret = 0;

    for (int i = 1; params[i]; i++) {
        if (is_built_in(params[i])) {
            my_printf("%s: shell built-in command.\n", params[i]);
        } else {
            check_where2(params[i], repo, &ret);
        }
    }
    return ret;
}
