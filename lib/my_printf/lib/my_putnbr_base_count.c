/*
** EPITECH PROJECT, 2023
** my_put_nbrbase
** File description:
** converts and displays a decimal number
** into a number in a given base
*/

#include "../include/my.h"

static void binaire(long long int nbr, int *ptr)
{
    if (nbr == 0)
        return;
    nbr = nbr / 2;
    binaire(nbr, ptr);
    *ptr += 1;
}

static void hexa(long int nbr, char const *base, int *ptr)
{
    if (nbr == 0)
        return;
    hexa(nbr / 16, base, ptr);
    *ptr += 1;
}

static void octa(long long int nbr, char const *base, int *ptr)
{
    if (nbr == 0)
        return;
    octa(nbr / 8, base, ptr);
    *ptr += 1;
}

static void apply_fonc_bin(long long int nb, int *ptr)
{
    if (nb >= 0)
        binaire(nb, ptr);
    if (nb < 0) {
        *ptr += 1;
        binaire(-nb, ptr);
    }
    return;
}

static void apply_fonc_hex(long long int nb, char const *base, int *ptr)
{
    if (nb >= 0)
        hexa(nb, base, ptr);
    if (nb < 0) {
        *ptr += 1;
        hexa(-nb, base, ptr);
    }
    return;
}

static void apply_fonc_octa(long long int nb, char const *base, int *ptr)
{
    if (nb >= 0)
        octa(nb, base, ptr);
    if (nb < 0) {
        *ptr += 1;
        octa(-nb, base, ptr);
    }
    return;
}

int my_putnbr_base_count(unsigned int nbr, char const *base, char *s, int *tab)
{
    long long int nb = nbr;
    int count = 0;
    int *ptr = &count;

    if (base == "0123456789")
        my_putnbr(nbr);
    if (my_strlen(base) == 2) {
        apply_fonc_bin(nb, ptr);
    }
    if (my_strlen(base) == 16) {
        apply_fonc_hex(nb, base, ptr);
    }
    if (my_strlen(base) == 8)
        apply_fonc_octa(nb, base, ptr);
    return count;
}
