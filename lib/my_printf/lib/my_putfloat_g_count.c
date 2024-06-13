/*
** EPITECH PROJECT, 2023
** emacs main.c
** File description:
** main.c
*/

#include "../include/my.h"
#include <stdio.h>

static double abs_val_g_count(double nb, int *tab)
{
    int cpt = 0;

    if (nb < 0) {
        nb = -nb;
        cpt++;
    }
    return nb;
}

static int print0_count(int i, int *tab, long int decimal)
{
    int cpt = 0;

    while (i > 0) {
        if (decimal / my_compute_power_rec(10, i) % 10 == 0) {
            cpt++;
            i--;
        } else
            break;
    }
    return cpt;
}

int my_putfloat_g_count(double decimal_first, int *tab)
{
    int i = 5;
    long int decimal = (long int)(abs_val_g_count(decimal_first,
    tab) * 1000000);
    int k = 0;
    int cpt = 0;

    cpt += count_digit(decimal / 1000000);
    if (decimal % 1000000 != 0) {
        cpt++;
        cpt += print0_count(i, tab, decimal);
        while (decimal % 10 == 0) {
            decimal /= 10;
            k++;
        }
        cpt += count_digit(decimal % my_compute_power_rec(10, 6 - k));
    }
    return cpt;
}

static int merge_count_next(double decimal_first_bis, int k,
    int *tab, int *tab2)
{
    int cpt = 0;

    if (tab2[2] >= 4)
        cpt += my_putexp_count(decimal_first_bis, k, tab, tab2[1]);
    else
        cpt += my_putfloat_g_count(decimal_first_bis, tab);
    return cpt;
}

int merge_count(double decimal_first, int k, int *tab)
{
    double decimal_first_bis = decimal_first;
    int cpt = 0;
    int tab2[3] = {0, 0, 0};

    if (decimal_first < 0)
        decimal_first = -decimal_first;
    if (decimal_first >= 10) {
        while (decimal_first >= 10) {
            decimal_first /= 10;
            tab2[2]++;
        }
    }
    if (decimal_first < 1) {
        while (decimal_first < 1) {
            decimal_first *= 10;
            tab2[2]++;
        }
    }
    cpt += merge_count_next(decimal_first_bis, k, tab, tab2);
    return cpt;
}
