/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-alexis.seymour
** File description:
** change_directory.c
*/

#include "goyave.h"

static int is_existing_next(char **params)
{
    struct stat stat_dir;

    stat(params[1], &stat_dir);
    if ((stat_dir.st_mode & __S_IFMT) != __S_IFDIR) {
        my_printf("%s: Not a directory.\n", params[1]);
        return 0;
    }
    if (access(params[1], X_OK) != 0) {
        my_printf("%s: Permission denied.\n", params[1]);
        return 0;
    }
    return 1;
}

static int is_existing(char **params)
{
    struct stat stat_dir;
    int error = stat(params[1], &stat_dir);

    if (my_strcmp(params[1], "-") == 0 || params[1] == NULL ||
    my_strcmp(params[1], "~") == 0)
        return -1;
    else if (my_arrlen(params) != 2) {
        my_printf("cd: Too many arguments.\n");
        return 0;
    }
    if (error == -1) {
        my_printf("%s: %s.\n", params[1], strerror(errno));
        return 0;
    }
    return is_existing_next(params);
}

int find_home_from_env(char ***env)
{
    int i = 0;
    int exit = 0;

    for (i = 0; (*env)[i] == NULL || exit == 0; i++) {
        if ((*env)[i][0] == 'H' && (*env)[i][1] == 'O'
        && (*env)[i][2] == 'M' &&
        (*env)[i][3] == 'E' && (*env)[i][4] == '=') {
            exit = 1;
        }
    }
    return i - 1;
}

void go_to_home(char ***env, int index_pwd)
{
    int k = find_home_from_env(env);
    char buffer[2024] = "";
    char *tmp = NULL;

    getcwd(buffer, 2024);
    chdir((*env)[k] + 5);
    tmp = my_strcat("PWD=", buffer);
    (*env)[index_pwd] = my_strcpy((*env)[index_pwd],
    tmp);
    free(tmp);
}

static int change_last_directory(char ***env, int index_old_pwd,
    int index_pwd, char *oldcwd)
{
    getcwd(oldcwd, 2024);
    if (index_old_pwd == -1) {
        my_printf(": No such file or directory.\n");
        return 1;
    }
    (*env)[index_pwd] = my_strcpy((*env)[index_pwd],
    my_strcat("PWD=", (*env)[index_old_pwd] + 7));
    chdir((*env)[index_old_pwd] + 7);
    (*env)[index_old_pwd] = my_strcpy((*env)[index_old_pwd],
    my_strcat("OLDPWD=", oldcwd));
    return 0;
}

static int change_directory_next(char ***env, char **params)
{
    char oldcwd[2048] = "";
    int index_pwd = find_pwd_from_env(env, params);
    int index_old_pwd = find_old_pwd_from_env(env, params);
    char *tmp = NULL;

    if (my_arrlen(params) == 1 || my_strcmp("~", params[1]) == 0) {
        getcwd(oldcwd, 2024);
        tmp = my_strcat("OLDPWD=", oldcwd);
        (*env)[index_old_pwd] = my_strcpy((*env)[index_old_pwd],
        tmp);
        free(tmp);
        go_to_home(env, index_pwd);
        return 0;
    } else if (my_strcmp("-", params[1]) == 0) {
        return change_last_directory(env, index_old_pwd, index_pwd, oldcwd);
    }
    return 0;
}

int change_directory(char ***env, char **params)
{
    char cwd[2048] = "";
    char oldcwd[2048] = "";
    int index_pwd = find_pwd_from_env(env, params);
    int index_old_pwd = find_old_pwd_from_env(env, params);

    if (is_existing(params) == 0) {
        return 1;
    }
    getcwd(oldcwd, 2048);
    if (my_arrlen(params) == 1 || my_strcmp("-", params[1]) == 0 ||
    my_strcmp("~", params[1]) == 0)
        return change_directory_next(env, params);
    (*env)[index_old_pwd] = my_strcpy((*env)[index_old_pwd],
    my_strcat("OLDPWD=", oldcwd));
    chdir(params[1]);
    getcwd(cwd, 2048);
    (*env)[index_pwd] = my_strcpy((*env)[index_pwd], my_strcat("PWD=", cwd));
    return 0;
}
