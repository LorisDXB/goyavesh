/*
** EPITECH PROJECT, 2023
** int to string
** File description:
** ..
*/

#include "my.h"

char *int_to_string(int nb)
{
    int len = how_many_digits(nb);
    char *number = malloc(sizeof(char) * len + 1);
    int i = 0;
    int temp = nb;

    while (i < len) {
        number[i] = '0' + temp % 10;
        temp = temp / 10;
        i++;
    }
    number[i] = '\0';
    return my_revstr(number);
}
