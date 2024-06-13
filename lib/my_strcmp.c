/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** Reproduce the behavior of the strcmp function
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 1;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    return (s1[i] - s2[i]);
}
