/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** find_pwd.c
*/
#include "goyave.h"

static void find_pwd_from_env2(char ***env, char **path, int i)
{
    path[0] = my_strdup("setenv");
    path[1] = my_strdup("PWD");
    path[2] = NULL;
    set_env(env, path);
    (*env)[i + 1] = NULL;
    free(path[0]);
    free(path[1]);
    free(path);
}

int find_pwd_from_env(char ***env, char **params)
{
    int exit = 0;
    int i = 0;
    char **path = malloc(sizeof(char *) * 4);

    while ((*env)[i] != NULL && exit == 0) {
        if (my_strncmp((*env)[i], "PWD=", 3) == 0) {
            exit = 1;
        }
        i++;
    }
    if (my_arrlen(*env) == i && params[1][0] != '-') {
        find_pwd_from_env2(env, path, i);
        return i;
    }
    free(path);
    return i - 1;
}

static void find_old_pwd_from_env2(char ***env, char **path, int i)
{
    path[0] = my_strdup("setenv");
    path[1] = my_strdup("OLDPWD");
    path[2] = NULL;
    set_env(env, path);
    (*env)[i + 1] = NULL;
    free(path[0]);
    free(path[1]);
    free(path);
}

int find_old_pwd_from_env(char ***env, char **params)
{
    int exit = 0;
    int i = 0;
    char **path = malloc(sizeof(char *) * 4);

    while ((*env)[i] != NULL && exit == 0) {
        if (my_strncmp((*env)[i], "OLDPWD=", 6) == 0) {
            free(path);
            return i;
        }
        i++;
    }
    if (my_arrlen(*env) == i && my_strcmp(params[1], "-") != 0) {
        find_old_pwd_from_env2(env, path, i);
        return i;
    }
    free(path);
    return -1;
}
