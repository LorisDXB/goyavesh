/*
** EPITECH PROJECT, 2023
** my strdup
** File description:
** Write a function that allocates memory and copies
** the string given as argument in it
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    int len;
    char *dup;

    len = my_strlen(str) + 1;
    dup = malloc(sizeof(char) * len);
    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, str);
    dup[len - 1] = '\0';
    return (dup);
}
