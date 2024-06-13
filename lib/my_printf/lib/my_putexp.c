/*
** EPITECH PROJECT, 2023
** my_putexp.c
** File description:
** emacs
*/

#include "../include/my.h"

static int print0(int i, int *tab)
{
    if (i < 10) {
        tab[3]++;
        my_putchar('0');
    }
}

int my_putexpnegative(float decimal_first, int etat_flag, int *tab,
    int decimal)
{
    int i = 0;

    while (decimal_first < 1) {
        decimal_first *= 10;
        i++;
    }
    if (decimal == 2)
        my_putfloat_g(decimal_first, tab);
    else
        my_putfloat(decimal_first, tab);
    if (etat_flag == 1) {
        tab[3] += 2;
        my_putstr("e-");
    } else {
        tab[3] += 2;
        my_putstr("E-");
    }
    print0(i, tab);
    my_putnbr(i);
}

static int print_e(int etat_flag, int *tab)
{
    if (etat_flag == 1) {
        tab[3] += 2;
        my_putstr("e+");
    } else {
        tab[3] += 2;
        my_putstr("E+");
    }
}

int my_putexppositive(float decimal_first, int etat_flag, int *tab,
    int decimal)
{
    int i = 0;

    while (decimal_first >= 10) {
        decimal_first /= 10;
        i++;
    }
    if (decimal == 2)
        my_putfloat_g(decimal_first, tab);
    else
        my_putfloat(decimal_first, tab);
    print_e(etat_flag, tab);
    if (i < 10) {
        tab[3]++;
        my_putchar('0');
    }
    my_putnbr(i);
}

int my_putexp(float decimal_first, int etat_flag, int *tab, int decimal)
{
    int cpt = my_putexp_count(decimal_first, etat_flag, tab, decimal);

    if (decimal_first == 0) {
        my_putstr("0.000000");
        print_e(etat_flag, tab);
        my_putstr("00");
        return 0;
    }
    if (decimal_first < 0) {
        decimal_first = -decimal_first;
        tab[3]++;
        my_putchar('-');
    }
    if (decimal_first >= 1) {
        my_putexppositive(decimal_first, etat_flag, tab, decimal);
    } else if (decimal_first < 1)
        my_putexpnegative(decimal_first, etat_flag, tab, decimal);
    return 0;
}
