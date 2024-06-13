/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** free_array.c
*/
#include "my.h"

void free_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
}
