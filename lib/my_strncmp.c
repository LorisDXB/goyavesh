/*
** EPITECH PROJECT, 2023
** muy strncmp
** File description:
** Reproduce the behavior of the strncmp function.
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int index)
{
    int i = 0;

    if (s1 == NULL)
        return 1;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i != index) {
        i++;
    }
    return (s1[i] - s2[i]);
}
