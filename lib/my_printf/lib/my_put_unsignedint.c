/*
** EPITECH PROJECT, 2023
** my_putsignedint
** File description:
** emacs
*/
#include "../include/my.h"

int my_put_unsignedint(unsigned int n, int *tab)
{
    if (n < 0) {
        my_put_unsignedint(4294967295 + n, tab);
    }
    if (n >= 10) {
        my_put_unsignedint(n / 10, tab);
        tab[3]++;
        my_putchar(n % 10 + '0');
    }
    if (n < 10) {
        tab[3]++;
        my_putchar(n % 10 + '0');
    }
}
