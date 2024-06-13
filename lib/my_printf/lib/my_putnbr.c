/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** print number
*/
#include "../include/my.h"

static void print_space_front_0(int cpt, int *tab, int nb)
{
    if (tab[1] - cpt > 0 && tab[8] == 0 && tab[7] == 1) {
        while (tab[1] - cpt > 0) {
            my_putchar('0');
            tab[1]--;
        }
    }
}

static void print_space_front_blank(int cpt, int *tab, int nb)
{
    if (tab[1] - cpt > 0 && tab[8] == 0 && tab[7] == 0) {
        while (tab[1] - cpt > 0) {
            my_putchar(' ');
            tab[1]--;
        }
    }
}

static void print_space_front(int cpt, int *tab, int nb)
{
    int negative = 0;

    if (nb >= 0 && tab[10] == 1)
        cpt++;
    print_space_front_blank(cpt, tab, nb);
    if (nb >= 0 && tab[10] == 1)
        my_putchar('+');
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        negative = 1;
        cpt --;
    }
    if (tab[9] == 1)
        cpt++;
    if (nb >= 0 && tab[9] >= 1 && tab[10] == 0 && negative == 0)
        my_putchar(' ');
    print_space_front_0(cpt, tab, nb);
}

static void print_space_back(int cpt, int *tab, int nb)
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

static void ma_fonctionflag(int nb, int *tab)
{
    char print;

    if (nb == 0)
        return;
    print = nb % 10;
    nb = nb - print;
    ma_fonctionflag(nb / 10, tab);
    my_putchar(print + 48);
    tab[3]++;
}

void my_putnbrflag(int nb, int *tab)
{
    print_space_front(count_digit(nb), tab, nb);
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        tab[3] += 2;
        nb = nb + 2000000000;
        nb = -nb;
    }
    if (nb < 0) {
        tab[3]++;
        nb = - nb;
        }
    if (nb == 0) {
        tab[3]++;
        my_putchar('0');
    }
    ma_fonctionflag(nb, tab);
    print_space_back(count_digit(nb), tab, nb);
}

static void ma_fonction(int nb)
{
    char print;

    if (nb == 0)
        return;
    print = nb % 10;
    nb = nb - print;
    ma_fonction(nb / 10);
    my_putchar(print + 48);
}

void my_putnbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = nb + 2000000000;
        nb = -nb;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = - nb;
    }
    if (nb == 0) {
        my_putchar('0');
    }
    ma_fonction(nb);
}
