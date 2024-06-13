/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** is_assign.c
*/

#include "../../include/goyave.h"

int is_assign(char **params)
{
    for (int i = 0; params[0][i] != '\0'; i++) {
        if (params[0][i] == '=')
            return 1;
    }
    return 0;
}
