/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** command_walias.c
*/

#include "../../include/goyave.h"

static int len_command(char *alias, char **params)
{
    int count = strlen(alias);

    for (int i = 1; params[i] != NULL; i++) {
        count++;
        count += strlen(params[i]);
    }
    return count;
}

char *command_walias(char *alias, char **params)
{
    char *command = malloc(sizeof(char) * (len_command(alias, params) + 1));

    command[0] = '\0';
    strcat(command, alias);
    for (int i = 1; params[i] != NULL; i++) {
        strcat(command, " ");
        strcat(command, params[i]);
    }
    return command;
}
