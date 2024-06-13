/*
** EPITECH PROJECT, 2023
** my_put_space
** File description:
** reproduce behavior of %10d for example
*/
#include <stdarg.h>
#include "../include/my.h"

static void hexa_count(int nbr, int *ptr)
{
    if (nbr == 0)
        return;
    hexa_count(nbr / 16, ptr);
    *ptr++;
}

static int x_flag(char *s, int *tab, va_list list)
{
    int nb = va_arg(list, int);
    int *len_nb = 0;

    hexa_count(nb, len_nb);
    for (int i = 0; i < tab[1] - *len_nb; i++) {
        my_putchar(' ');
        tab[3]++;
    }
    my_putnbr_base(nb, "0123456789ABCDEF", tab, s);
    tab[3] += *len_nb;
}

static int s_flag(char *s, int *tab, va_list list)
{
    char *str = va_arg(list, char *);

    for (int i = 0; i < tab[1] - my_strlen(str); i++) {
        my_putchar(' ');
        tab[3]++;
    }
    my_putstr(str);
    tab[3] += my_strlen(str);
}

static int c_flag(char *s, int *tab, va_list list)
{
    for (int i = 0; i < tab[1] - 1; i++) {
        my_putchar(' ');
        tab[3]++;
    }
    my_putchar(va_arg(list, int));
    tab[3]++;
}

static int i_flag(char *s, int *tab, va_list list)
{
    int nb;

    nb = va_arg(list, int);
    for (int i = 0; i < tab[1] - count_digit(nb); i++) {
        my_putchar(' ');
        tab[3]++;
    }
    my_putnbr(nb);
    tab[3] += count_digit(nb);
}

static int redirection(char *s, int *tab, va_list list, int nb_chiffre)
{
    switch (s[tab[0]]) {
    case 'd':
    case 'i':
        i_flag(s, tab, list);
    case 'c':
        c_flag(s, tab, list);
    case 's':
        s_flag(s, tab, list);
    default:
        tab[3] -= nb_chiffre;
    }
}

void my_put_space(char *s, int *tab, va_list list)
{
    int nb_chiffre = 0;
    int nb;
    int nb_space = 0;

    while (s[tab[0]] >= '0' && s[tab[0]] <= '9') {
        tab[0]++;
        nb_chiffre++;
    }
    redirection(s, tab, list, nb_chiffre);
}
