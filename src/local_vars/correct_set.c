/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** correct_set.c
*/

#include "../../include/goyave.h"
#include <stdio.h>

int len_array(char **array)
{
    int count = 0;

    while (array[count] != NULL)
        count++;
    return count;
}

int complete_dec(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '=')
            return 1;
    }
    return 0;
}

static int correct_complete_dec(char *str)
{
    if (str[0] < 65 || (str[0] > 90 && str[0] < 97) || str[0] > 122) {
        my_printf("set: Variable name must begin with a letter.\n");
        return 84;
    }
    for (int j = 1; str[j] != '='; j++) {
        if (str[j] < 48 || (str[j] > 57 && str[j] < 65)
            || (str[j] > 90 && str[j] < 97) || str[j] > 122) {
            my_printf("set: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return 84;
        }
    }
    return 0;
}

static int correct_name(char *str)
{
    if (str[0] < 65 || (str[0] > 90 && str[0] < 97) || str[0] > 122) {
        my_printf("set: Variable name must begin with a letter.\n");
        return 84;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || (str[i] > 57 && str[i] < 65)
            || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
            my_printf("set: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return 84;
        }
    }
    return 0;
}

static int correct_dec(char **command, int *i)
{
    if (correct_name(command[*i]) == 84)
        return 84;
    if (command[*i +1] != NULL && strcmp(command[*i + 1], "=") == 0)
        *i += 3;
    else
        *i += 1;
    return 0;
}

static int sub_correct_set(char **command, int *i)
{
    if (complete_dec(command[*i]) == 1) {
        if (correct_complete_dec(command[*i]) == 84)
            return 84;
        else
            *i += 1;
    } else if (complete_dec(command[*i]) == 0 && correct_dec(command, i) == 84)
        return 84;
    return 0;
}

int correct_set(char **command)
{
    int i = 1;

    if (strcmp(command[0], "set") != 0 && strcmp(command[0], "local") != 0)
        i = 0;
    while (i < len_array(command)) {
        if (sub_correct_set(command, &i) == 84)
            return 84;
    }
    return 0;
}
