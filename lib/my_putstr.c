/*
** EPITECH PROJECT, 2023
** my putstr
** File description:
** Write a function that displays, one-by-one, the characters of a stri
** The address of the string’s first character will be found in the pointer
** passed as a parameter to the function
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        my_putchar(str[i]);
        i++;
    }
    return my_strlen(str);
}

int my_countstr_two(char const *str, int acc)
{
    int i = 0;
    int len = my_strlen(str);

    if (acc != 0 && acc <= len)
        len = acc;
    while (i < len) {
        i++;
    }
    return len;
}

int my_putstr_two(char const *str, int acc)
{
    int i = 0;
    int len = my_strlen(str);

    if (acc != 0 && acc <= len)
        len = acc;
    while (i < len) {
        my_putchar(str[i]);
        i++;
    }
    return len;
}
