/*
** EPITECH PROJECT, 2023
** my strlen
** File description:
** ..
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
