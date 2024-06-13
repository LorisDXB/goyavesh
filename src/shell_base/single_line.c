/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-alexis.seymour
** File description:
** single_line.c
*/

#include "goyave.h"

int single_line(repo_t *repo)
{
    size_t len = 0;
    char *buffer = NULL;
    int return_value = 0;
    int car = 0;

    while (car != -1) {
        car = getline(&buffer, &len, stdin);
        if (car == -1 || car == 1)
            break;
        buffer[car] = '\0';
        if (my_strcmp(buffer, "exit") == 0)
            break;
        return_value = verif_command(repo, buffer);
    }
    if (WTERMSIG(return_value) != 0)
        my_printf("%s\n", strsignal(WTERMSIG(return_value)));
    return return_value;
}
