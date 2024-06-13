/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** Write a function that reverses a string
*/
#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    char temp;

    while (i <= len / 2) {
        temp = str[len - i];
        str[len - i] = str[i];
        str[i] = temp;
        i++;
    }
    return (str);
}
