/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** get_var.c
*/

#include <stdlib.h>

static int len_var_name(char *string)
{
    int len = 0;

    for (int i = 0; string[i] != '=' && string[i] != '\0'; i++)
        len++;
    return len;
}

char *get_var_name(char *string)
{
    char *name = malloc(sizeof(char) * (len_var_name(string) + 1));
    int index = 0;

    for (int i = 0; string[i] != '=' && string[i] != '\0'; i++) {
        name[index] = string[i];
        index++;
    }
    name[index] = '\0';
    return name;
}

static int len_var_value(char *string)
{
    int len = 0;
    int i = 0;

    while (string[i] != '=' && string[i] != '\0')
        i++;
    for (int j = i + 1; string[j] != '\0'; j++)
        len++;
    return len;
}

char *get_var_value(char *string)
{
    char *value;
    int i = 0;
    int index = 0;

    if (len_var_value(string) == 0)
        return NULL;
    value = malloc(sizeof(char) * (len_var_value(string) + 1));
    while (string[i] != '=' && string[i] != '\0')
        i++;
    for (int j = i + 1; string[j] != '\0'; j++) {
        value[index] = string[j];
        index++;
    }
    value[index] = '\0';
    return value;
}
