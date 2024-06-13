/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** my_array_to_str.c
*/

#include "my.h"

char *my_array_to_str(char **tab)
{
    int i = 0;
    char *str = "\0";

    while (tab[i] != NULL) {
        str = my_strcat(str, tab[i]);
        i++;
    }
    for (int j = 0; tab[j] != NULL; j++)
        free(tab[j]);
    free(tab);
    return str;
}
