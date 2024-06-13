/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-keyvan.goddard
** File description:
** my_strdup_start_end.c
*/
#include "goyave.h"

char *my_strdup_start_end(char *src, int start, int end)
{
    char *new = NULL;
    int j = 0;

    if (!src)
        return NULL;
    new = malloc(sizeof(char) * (end - start + 2));
    if (!new) {
        perror("Malloc error");
        exit(84);
    }
    for (int i = start; src[i] && i < end; i++) {
        new[j] = src[i];
        j++;
    }
    new[j] = '\0';
    return new;
}
