/*
** EPITECH PROJECT, 2024
** arraylen
** File description:
** my_arraylen
*/

#include "my.h"

int my_arrlen(char **a)
{
    int i = 0;

    while (a[i] != NULL)
        i++;
    return i;
}

int my_arrlen2(int **a)
{
    int i = 0;

    while (a[i] != NULL)
        i++;
    return i;
}
