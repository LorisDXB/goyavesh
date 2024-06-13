/*
** EPITECH PROJECT, 2024
** GoyaveSh_mirror
** File description:
** var_used.c
*/

#include "../../include/goyave.h"

char *array_to_str_spaces(char **tab)
{
    char *str = "\0";

    str = my_strcat(str, tab[0]);
    for (int i = 1; tab[i] != NULL; i++) {
        str = my_strcat(str, " ");
        str = my_strcat(str, tab[i]);
    }
    return str;
}

static int alphanum(char c)
{
    if (c != '\0' && ((c > 47 && c < 58)
        || (c > 64 && c < 91) || (c > 96 && c < 123))) {
        return 1;
    }
    return 0;
}

char *find_var_name(char *buffer, int *i)
{
    int count = 0;
    char *name = NULL;
    int index = 0;

    *i += 1;
    for (int j = *i; alphanum(buffer[j]) == 1; j++)
        count++;
    name = malloc(sizeof(char) * (count + 1));
    for (; alphanum(buffer[*i]) != 0; *i += 1) {
        name[index] = buffer[*i];
        index++;
    }
    name[index] = '\0';
    return name;
}

static char *env_var_value(char *env_var)
{
    char *value = NULL;
    int i = 0;
    int j = 0;

    while (env_var[i] != '=')
        i++;
    value = malloc(sizeof(char) * (my_strlen(env_var) - i));
    for (int k = i + 1; env_var[k] != '\0'; k++) {
        value[j] = env_var[k];
        j++;
    }
    value[j] = '\0';
    return value;
}

static char *find_var(char **env, dict_t *local_vars, char *var)
{
    int index = 0;
    char *name = find_var_name(var, &index);
    dict_t *tmp = local_vars;

    while (tmp) {
        if (strcmp(tmp->key, name) == 0) {
            return tmp->value;
        }
        tmp = tmp->next;
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], name, my_strlen(name)) == 0) {
            return env_var_value(env[i]);
        }
    }
    return NULL;
}

static void modify_param(char **params, char *to_dup, int i)
{
    if (to_dup) {
        params[i] = strdup(to_dup);
    }
}

char **replace_vars(repo_t *repo, char *buffer, char **params)
{
    char *to_dup = NULL;

    if (all_vars_exist(*repo->env, repo->local_vars, buffer) == 1)
        return NULL;
    for (int i = 0; params[i] != NULL; i++) {
        if (params[i][0] == '$' && my_strlen(params[i]) > 1) {
            to_dup = find_var(*repo->env, repo->local_vars, params[i]);
            modify_param(params, to_dup, i);
        }
    }
    return params;
}

int is_var_used(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '$' && i != my_strlen(buffer) - 1
            && buffer[i + 1] != ' ')
            return 1;
    }
    return 0;
}
