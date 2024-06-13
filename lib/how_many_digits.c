/*
** EPITECH PROJECT, 2023
** home many digits
** File description:
** ..
*/
#include "my.h"


int how_many_digits(int nb)
{
    int i = 0;

    while (nb >= 10) {
        nb = nb / 10;
        i++;
    }
    return i + 1;
}
