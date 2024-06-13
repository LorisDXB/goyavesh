/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-alexis.seymour
** File description:
** inf_boucle.c
*/

#include "goyave.h"

static int check_command9(repo_t *repo, char *buffer, char **params)
{
    int ret = 0;

    if (strcmp(params[0], "bg") == 0) {
        ret = exec_bg(repo, params);
        free_array(params);
        return ret;
    }
    free_array(params);
    ret = execute_command(repo, repo->env, buffer);
    repo->last_return = ret;
    return ret;
}

static int check_command8(repo_t *repo, char *buffer, char **params)
{
    int ret = 0;

    if (strcmp(params[0], "jobs") == 0) {
        ret = jobs(repo, params);
        free_array(params);
        return ret;
    }
    if (strcmp(params[0], "guava") == 0) {
        goyave_art();
        free_array(params);
        return ret;
    }
    return check_command9(repo, buffer, params);
}

static int check_command7(repo_t *repo, char *buffer, char **params)
{
    int ret = 0;

    if (strcmp(params[0], "fg") == 0) {
        ret = exec_fg(repo, params);
        free_array(params);
        return ret;
    }
    if (my_strcmp(params[0], "set") == 0 || strcmp(params[0], "local") == 0
        || is_assign(params) == 1) {
        ret = set_local_var(repo, params);
        free_array(params);
        return ret;
    }
    if (strcmp(params[0], "export") == 0) {
        ret = export_env_var(repo, params);
        free_array(params);
        return ret;
    }
    return check_command8(repo, buffer, params);
}

static int check_command6(repo_t *repo, char *buffer, char **params)
{
    int ret = 0;
    char *command = NULL;

    if (strcmp(params[0], "where") == 0) {
        ret = check_where(repo, params);
        free_array(params);
        return ret;
    }
    if (is_alias(repo->alias, params[0]) != NULL) {
        command = command_walias(is_alias(repo->alias, params[0]), params);
        ret = execute_command(repo, repo->env, command);
        free(command);
        free_array(params);
        return ret;
    }
    return check_command7(repo, buffer, params);
}

static int check_command5(repo_t *repo, char *buffer, char **params)
{
    int ret = 0;

    if (strcmp(params[0], "which") == 0) {
        ret = check_which(repo, params);
        free_array(params);
        return ret;
    }
    if (strcmp(params[0], "alias") == 0) {
        ret = alias_command(repo, params);
        free_array(params);
        return ret;
    }
    if (strcmp(params[0], "unalias") == 0) {
        ret = unalias_command(repo, params);
        free_array(params);
        return ret;
    }
    return check_command6(repo, buffer, params);
}

static int check_command4(repo_t *repo, char *buffer, char **params)
{
    int ret = 0;

    if (my_strcmp(params[0], "env") == 0) {
        ret = print_env(*(repo->env));
        free_array(params);
        repo->last_return = ret;
        return ret;
    }
    if (my_strcmp(params[0], "cd") == 0) {
        ret = change_directory(repo->env, params);
        free_array(params);
        repo->last_return = ret;
        return ret;
    }
    return check_command5(repo, buffer, params);
}

static int check_command3(repo_t *repo, char *buffer, char **params)
{
    int ret = 0;

    if (my_strcmp(params[0], "unsetenv") == 0) {
        ret = unset_env_hub(repo->env, params);
        free_array(params);
        repo->last_return = ret;
        return ret;
    }
    if (strcmp(params[0], "history") == 0) {
        free_array(params);
        print_history(repo->pwd);
        repo->last_return = 0;
        return 0;
    }
    if (strcmp(params[0], "unset") == 0) {
        ret = unset_local_var(repo, params);
        free_array(params);
        return ret;
    }
    return check_command4(repo, buffer, params);
}

static int check_command2(repo_t *repo, char *buffer, char **params)
{
    int ret = 0;

    if (my_strcmp(params[0], "exit") == 0) {
        free_array(params);
        repo->last_return = 0;
        return 0;
    }
    if (my_strcmp(params[0], "setenv") == 0) {
        if (my_arrlen(params) == 1) {
            ret = print_env(*(repo->env));
            free_array(params);
            repo->last_return = ret;
            return ret;
        }
        ret = set_env(repo->env, params);
        free_array(params);
        repo->last_return = ret;
        return ret;
    }
    return check_command3(repo, buffer, params);
}

int check_command(repo_t *repo, char *buffer)
{
    char **params = my_str_to_word_array(buffer, " \t\0");

    if (my_arrlen(params) == 2 && my_strcmp(params[0], "echo") == 0
    && my_strcmp(params[1], "$?") == 0) {
        my_printf("%d\n", repo->last_return);
        free_array(params);
        return 0;
    }
    if (is_var_used(buffer) == 1) {
        params = replace_vars(repo, buffer, params);
        if (params == NULL)
            return 1;
        buffer = array_to_str_spaces(params);
    }
    return check_command2(repo, buffer, params);
}

int verif_command(repo_t *repo, char *buffer)
{
    char **all_params = NULL;
    int i = 0;
    int exit_value = 0;
    char *pointer = NULL;

    buffer = format(repo, buffer);
    pointer = buffer;
    if (buffer == NULL)
        return 0;
    buffer = del_space(buffer);
    all_params = my_str_to_word_array(buffer, ";\n\0");
    while (all_params[i] != NULL) {
        exit_value = execute_logical_or(repo, all_params[i]);
        if (exit_value == 257)
            return 1;
        i++;
    }
    free(pointer);
    free_array(all_params);
    return exit_value;
}
