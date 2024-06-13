/*
** EPITECH PROJECT, 2023
** my_put_nbrbase
** File description:
** converts and displays a decimal number
** into a number in a given base
*/

#include "../include/my.h"

static void print_space_front_0(int cpt, int *tab, long long int nb)
{
    if (tab[1] - cpt > 0 && tab[8] == 0 && tab[7] == 1) {
        while (tab[1] - cpt > 0) {
            my_putchar('0');
            tab[1]--;
        }
    }
}

static void print_space_front_blank(int cpt, int *tab, long long int nb)
{
    if (tab[1] - cpt > 0 && tab[8] == 0 && tab[7] == 0) {
        while (tab[1] - cpt > 0) {
            my_putchar(' ');
            tab[1]--;
        }
    }
}

static void print_space_front(int cpt, int *tab, long long int nb)
{
    int negative = 0;

    if (nb >= 0 && tab[10] == 1)
        cpt++;
    print_space_front_blank(cpt, tab, nb);
    if (nb >= 0 && tab[10] == 1)
        my_putchar('+');
    if (tab[9] == 1)
        cpt++;
    print_space_front_0(cpt, tab, nb);
}

static void print_space_back(int cpt, int *tab, long long int nb)
{
    if (tab[6] != 0)
        cpt += 2;
    if (nb >= 0 && tab[10] == 1)
        cpt++;
    if (tab[1] - cpt > 0 && tab[8] != 0) {
        while (tab[1] - cpt > 0) {
            my_putchar(' ');
            tab[1]--;
        }
    }
}

static void hexa(long int nbr, char const *base, int *tab)
{
    char print;

    if (nbr == 0)
        return;
    print = base[nbr % 16];
    hexa(nbr / 16, base, tab);
    tab[3]++;
    my_putchar(print);
}

static void octa(long long int nbr, char const *base, int *tab)
{
    char print;

    if (nbr == 0)
        return;
    print = nbr % 8;
    octa(nbr / 8, base, tab);
    tab[3]++;
    my_putchar(print + 48);
}

static void apply_fonc_hex(long long int nb, char const *base, int *tab)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    if (nb > 0)
        hexa(nb, base, tab);
    if (nb < 0) {
        tab[3]++;
        my_putchar('-');
        hexa(-nb, base, tab);
    }
    return;
}

static void apply_fonc_octa(long long int nb, char const *base, int *tab)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    if (nb > 0)
        octa(nb, base, tab);
    if (nb < 0) {
        tab[3]++;
        my_putchar('-');
        octa(-nb, base, tab);
    }
    return;
}

int my_putnbr_base_flag(unsigned int nbr, char const *base,
    int *tab, char *s)
{
    long long int nb = nbr;
    int cpt = my_putnbr_base_count(nbr, base, s, tab);

    print_space_front(cpt, tab, nb);
    if (base == "0123456789")
        my_putnbr(nbr);
    if (my_strlen(base) == 16) {
        apply_fonc_hex(nb, base, tab);
    }
    if (my_strlen(base) == 8)
        apply_fonc_octa(nb, base, tab);
    print_space_back(cpt, tab, nb);
}
