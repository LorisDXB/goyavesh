/*
** EPITECH PROJECT, 2023
** emacs main.c
** File description:
** main.c
*/
#include "../include/my.h"

static double abs_val(double nb, int *tab)
{
    if (nb < 0) {
        nb = -nb;
        tab[3]++;
        my_putchar('-');
    }
    return nb;
}

int my_putfloat(double decimal_first, int *tab)
{
    int i = 5;
    long int decimal = (long int)(abs_val(decimal_first, tab) * 1000000);
    int cpt = my_putfloat_count(decimal_first, tab);

    my_putnbr(decimal / 1000000);
    my_putchar('.');
    tab[3]++;
    while (i > 0) {
        if (decimal / my_compute_power_rec(10, i) % 10 == 0) {
            tab[3]++;
            my_putchar('0');
            i--;
        } else
            break;
    }
    my_putnbr(decimal % 1000000);
}
