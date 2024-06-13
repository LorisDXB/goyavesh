/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-alexis.seymour
** File description:
** del_space.c
*/

#include "my.h"

char *del_space(char *str)
{
    int start = 0;
    int i = my_strlen(str);

    if (str == NULL)
        return NULL;
    while (i > 0 && str[i - 1] == ' ') {
        i--;
    }
    str[i] = '\0';
    while (str[start] == ' ')
        start++;
    str = str + start;
    return str;
}
