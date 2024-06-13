/*
** EPITECH PROJECT, 2023
** switch_case
** File description:
** emacs
*/

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include "../include/my.h"


static void if_long2(char *s, int *tab, va_list ap)
{
    switch (s[tab[0]]) {
    case 'o' :
        my_putnbr_base(va_arg(ap, long int), "01234567", tab, s);
        break;
    }
}

static void if_long(char *s, int *tab, va_list ap)
{
    tab[0]++;
    switch (s[tab[0]]) {
    case 'i' :
    case 'd' :
        my_putnbr(va_arg(ap, long int));
        break;
    case 'u' :
        my_put_unsignedint(va_arg(ap, long int), tab);
        break;
    case 'x' :
        my_putnbr_base_flag(va_arg(ap, long int), "0123456789abcdef", tab, s);
        break;
    case 'X' :
        my_putnbr_base_flag(va_arg(ap, long int), "0123456789ABCDEF", tab, s);
        break;
    default:
        if_long2(s, tab, ap);
    }
}

static void if8(char *s, int *tab, va_list ap)
{
    switch (s[tab[0]]) {
    case 'l':
        if_long(s, tab, ap);
        break;
    case 'g':
        merge(va_arg(ap, double), 1, tab);
        break;
    case 'G':
        merge(va_arg(ap, double), 0, tab);
        break;
    default:
        if9(s, tab, ap);
    }
}

static void if7(char *s, int *tab, va_list ap)
{
    int *ptr;
    float nb;

    switch (s[tab[0]]) {
    case 'E':
        nb = (float)va_arg(ap, double);
        my_putexp(nb, 0, tab, 0);
        break;
    case 'n':
        ptr = va_arg(ap, int *);
        *ptr = tab[3] + 2;
        break;
    default:
        if8(s, tab, ap);
    }
}

static void if6(char *s, int *tab, va_list ap)
{
    float nb;
    char *str;

    switch (s[tab[0]]) {
    case 'e':
        nb = (float)va_arg(ap, double);
        my_putexp(nb, 1, tab, 0);
        break;
    case 's':
        my_putstrflag(va_arg(ap, char *), tab);
        break;
    default:
        if7(s, tab, ap);
    }
}

static void if5(char *s, int *tab, va_list ap)
{
    int nb;
    unsigned int n;

    switch (s[tab[0]]) {
    case 'X':
        nb = va_arg(ap, int);
        my_put_hashtag(tab, 1, 1, nb);
        my_putnbr_base_flag(nb, "0123456789ABCDEF", tab, s);
        break;
    case 'u':
        n = va_arg(ap, unsigned int);
        my_put_unsignedint(n, tab);
        break;
    case 'm':
        my_put_error(errno, tab);
        break;
    default:
        if6(s, tab, ap);
    }
}

static void if4(char *s, int *tab, va_list ap)
{
    void *ptr;
    int nb;

    switch (s[tab[0]]) {
    case 'p':
        ptr = va_arg(ap, void *);
        my_putstr("0x");
        tab[3] += 2;
        my_putnbr_base((long long int)ptr, "0123456789abcdef", tab, s);
        break;
    case 'x':
        nb = va_arg(ap, int);
        my_put_hashtag(tab, 0, 1, nb);
        my_putnbr_base_flag(nb, "0123456789abcdef", tab, s);
        break;
    default:
        if5(s, tab, ap);
        }
}

static void if3(char *s, int *tab, va_list ap)
{
    double f_nb;
    int nb;
    char *str;

    switch (s[tab[0]]) {
    case 'f':
    case 'F':
        f_nb = va_arg(ap, double);
        my_putfloat_flag(f_nb, tab);
        break;
    case 'o':
        nb = va_arg(ap, int);
        my_put_hashtag(tab, 1, 0, nb);
        my_putnbr_base_flag(nb, "01234567", tab, s);
        break;
    default:
        if4(s, tab, ap);
    }
}

static void if2(char *s, int *tab, va_list ap)
{
    switch (s[tab[0]]) {
    case 'i':
        my_putnbrflag(va_arg(ap, int), tab);
        break;
    case 'd':
        my_putnbrflag(va_arg(ap, int), tab);
        break;
    case 'c':
        my_putcharflag(va_arg(ap, int), tab);
        tab[3]++;
        break;
    default:
        if3(s, tab, ap);
    }
}

void switch_next(char *s, int *tab, va_list ap)
{
    char *str;

    switch (s[tab[0]]) {
    default:
        if2(s, tab, ap);
    }
}
