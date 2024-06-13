/*
** EPITECH PROJECT, 2024
** input
** File description:
** input
*/

#include "my.h"


char *my_input(char *print)
{
    int size = 0;
    char *buffer = malloc(sizeof(char) * 32000);

    my_putstr(print);
    while (size == 0) {
        size = read(0, buffer, 32000);
    }
    buffer[size - 1] = '\0';
    return buffer;
}
