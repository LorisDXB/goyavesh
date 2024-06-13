/*
** EPITECH PROJECT, 2023
** my_put_nbrbase
** File description:
** converts and displays a decimal number
** into a number in a given base
*/

#include "../include/my.h"

static void binaire(long long int nbr, int *tab)
{
    char print;

    if (nbr == 0)
        return;
    print = nbr % 2;
    nbr = nbr / 2;
    binaire(nbr, tab);
    my_putchar(print + 48);
    tab[3]++;
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

static void apply_fonc_bin(long long int nb, int *tab)
{
    tab[5] = 0;
    if (nb >= 0)
        binaire(nb, tab);
    if (nb < 0) {
        tab[3]++;
        my_putchar('-');
        binaire(-nb, tab);
    }
    return;
}

static void apply_fonc_hex(long long int nb, char const *base, int *tab)
{
    if (nb >= 0)
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
    if (nb >= 0)
        octa(nb, base, tab);
    if (nb < 0) {
        tab[3]++;
        my_putchar('-');
        octa(-nb, base, tab);
    }
    return;
}

int my_putnbr_base(unsigned int nbr, char const *base, int *tab, char *s)
{
    long long int nb = nbr;

    if (base == "0123456789")
        my_putnbr(nbr);
    if (my_strlen(base) == 2) {
        apply_fonc_bin(nb, tab);
    }
    if (my_strlen(base) == 16) {
        apply_fonc_hex(nb, base, tab);
    }
    if (my_strlen(base) == 8)
        apply_fonc_octa(nb, base, tab);
    return 0;
}
