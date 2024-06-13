/*
** EPITECH PROJECT, 2023
** emacs main.c
** File description:
** main.c
*/

#include "../include/my.h"

static void print_space_front_0(int cpt, int *tab, double nb)
{
    if (tab[1] - cpt > 0 && tab[8] == 0 && tab[7] == 1) {
        while (tab[1] - cpt > 0) {
            my_putchar('0');
            tab[1]--;
        }
    }
}

static void print_space_front_blank(int cpt, int *tab, double nb)
{
    if (tab[1] - cpt > 0 && tab[8] == 0 && tab[7] == 0) {
        while (tab[1] - cpt > 0) {
            my_putchar(' ');
            tab[1]--;
        }
    }
}

static void print_space_front(int cpt, int *tab, double nb)
{
    int negative = 0;

    if (nb >= 0 && tab[10] == 1)
        cpt++;
    print_space_front_blank(cpt, tab, nb);
    if (nb >= 0 && tab[10] == 1)
        my_putchar('+');
    if (tab[9] == 1)
        cpt++;
    if (nb >= 0 && tab[9] >= 1 && tab[10] == 0 && negative == 0)
        my_putchar(' ');
    print_space_front_0(cpt, tab, nb);
}

static void print_space_back(int cpt, int *tab, double nb)
{
    if (nb >= 0 && tab[10] == 1)
        cpt++;
    if (tab[9] > 1)
        cpt++;
    if (tab[9] == 1)
        cpt++;
    if (tab[1] - cpt > 0 && tab[8] != 0) {
        while (tab[1] - cpt > 0) {
            my_putchar(' ');
            tab[1]--;
        }
    }
}

int my_putfloat_count(double decimal_first, int *tab)
{
    int i = 5;
    long int decimal = (long int)decimal_first * 1000000;
    int cpt = 0;

    if (decimal < 0) {
        decimal = -decimal;
        cpt++;
    }
    cpt += 1 + count_digit(decimal / 1000000);
    while (i > 0) {
        if (decimal / my_compute_power_rec(10, i) % 10 == 0) {
            cpt++;
            i--;
        } else
            break;
    }
    cpt += count_digit(decimal % 1000000);
    return cpt;
}

static double abs_val(double nb, int *tab)
{
    if (nb < 0) {
        nb = -nb;
        tab[3]++;
        my_putchar('-');
    }
    return nb;
}

int my_putfloat_flag(double decimal_first, int *tab)
{
    int i = 5;
    long int decimal = (long int)(abs_val(decimal_first, tab) * 1000000);
    int cpt = my_putfloat_count(decimal_first, tab);

    print_space_front(cpt, tab, decimal_first);
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
    print_space_back(cpt, tab, decimal_first);
}
