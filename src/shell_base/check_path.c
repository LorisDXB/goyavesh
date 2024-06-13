/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-alexis.seymour
** File description:
** check_path.c
*/
#include "goyave.h"

char **default_path(void)
{
    char **tab = malloc(sizeof(char *) * 7);

    tab[0] = my_strdup("/usr/local/bin");
    tab[1] = my_strdup("/usr/local/sbin");
    tab[2] = my_strdup("/usr/bin");
    tab[3] = my_strdup("/usr/sbin");
    tab[4] = my_strdup("/bin");
    tab[5] = my_strdup("/sbin");
    tab[6] = NULL;
    return tab;
}

int check_word_path(char *env)
{
    if (env == NULL)
        return 0;
    if (env[0] == 'P' && env[1] == 'A' && env[2] == 'T' &&
    env[3] == 'H' && env[4] == '=')
        return 1;
    return 0;
}

char **check_path(char ***env)
{
    int exit = 0;
    int i = 0;
    char **path = NULL;

    while ((*env) != NULL && (*env)[i] != NULL && exit == 0) {
        exit = check_word_path((*env)[i]);
        i++;
    }
    if (i == 0 || (*env)[i - 1] == NULL) {
        set_env(env, my_str_to_word_array("setenv PATH /usr/local/bin:"
        "/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin", " "));
        return default_path();
    }
    path = my_str_to_word_array_path((*env)[i - 1] + 5);
    return path;
}

static void free_str(char *new, char *c_path)
{
    free(new);
    free(c_path);
}

char *get_file_to_path(char **command, char **path)
{
    int i = 0;
    char *new = NULL;
    char *c_path = NULL;

    if (open(command[0], O_RDONLY) != -1)
        return command[0];
    while (path[i] != NULL) {
        c_path = my_strcat("/", command[0]);
        new = my_strcat(path[i], c_path);
        if (open(new, O_RDONLY) != -1) {
            command[0] = my_strcpy(command[0], my_strcat(path[i],
            my_strcat("/", command[0])));
            free_str(new, c_path);
            return command[0];
        } else {
            free_str(new, c_path);
        }
        i++;
    }
    return NULL;
}
