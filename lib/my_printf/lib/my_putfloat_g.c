/*
** EPITECH PROJECT, 2023
** emacs main.c
** File description:
** main.c
*/

#include "../include/my.h"
#include <stdio.h>

static double abs_val_g(double nb, int *tab)
{
    if (nb < 0) {
        nb = -nb;
        tab[3]++;
        my_putchar('-');
    }
    return nb;
}

static int print0(int i, int *tab, int cpt, long int decimal)
{
    while (i > 0) {
        if (decimal / my_compute_power_rec(10, i) % 10 == 0) {
            tab[3]++;
            my_putchar('0');
            i--;
            cpt++;
        } else
            break;
    }
    return cpt;
}

int my_putfloat_g(double decimal_first, int *tab)
{
    int i = 5;
    long int decimal = (long int)(abs_val_g(decimal_first, tab) * 1000000);
    int k = 0;
    int cpt = 0;

    tab[3]++;
    my_putnbr(decimal / 1000000);
    if (decimal % 1000000 != 0) {
        my_putchar('.');
        tab[3]++;
        cpt += print0(i, tab, cpt, decimal);
        while (decimal % 10 == 0) {
            decimal /= 10;
            k++;
        }
        my_putnbr(decimal % my_compute_power_rec(10, 6 - k));
    }
    return cpt;
}

int getting_i(double decimal_first, int i)
{
    if (decimal_first < 1 && decimal_first != 0) {
        i = 0;
        while (decimal_first < 1) {
            decimal_first *= 10;
            i++;
        }
    }
    return i;
}

int merge(double decimal_first, int etat_flag, int *tab)
{
    int i = 0;
    double decimal_first_bis = decimal_first;

    if (decimal_first < 0)
        decimal_first = -decimal_first;
    if (decimal_first >= 10) {
        while (decimal_first >= 10) {
            decimal_first /= 10;
            i++;
        }
    }
    i = getting_i(decimal_first, i);
    if (i >= 4)
        my_putexp(decimal_first_bis, etat_flag, tab, 2);
    else
        my_putfloat_g(decimal_first_bis, tab);
}
