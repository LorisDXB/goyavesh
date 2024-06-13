/*
** EPITECH PROJECT, 2023
** my strcpy
** File description:
** Write a function that copies a string into another.
** The destination string will already have enough memory
** to copy the source string.
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL) {
        dest = NULL;
        return NULL;
    }
    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
