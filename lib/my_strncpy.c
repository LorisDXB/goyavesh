/*
** EPITECH PROJECT, 2023
** my strncpy
** File description:
** Write a function that copies n characters from a string into another.
** The destination string will already have enough
** memory to contain n characters.
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int k)
{
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0' && i != k) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
