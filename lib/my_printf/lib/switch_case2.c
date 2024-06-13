/*
** EPITECH PROJECT, 2023
** switch_case2
** File description:
** emacs
*/

#include <stdarg.h>
#include "../include/my.h"

static void ifh2(char *s, int *tab, va_list ap)
{
    switch (s[tab[0]]) {
    case 'o' :
        my_putnbr_base((short)va_arg(ap, int), "01234567", tab, s);
        break;
    }
}

static void ifh(char *s, int *tab, va_list ap)
{
    tab[0]++;
    switch (s[tab[0]]) {
    case 'i':
    case 'd':
        my_putnbr((short)va_arg(ap, int));
        break;
    case 'u':
        my_put_unsignedint((short)va_arg(ap, int), tab);
        break;
    case 'x':
        my_putnbr_base((short)va_arg(ap, int), "0123456789abcdef", tab, s);
        break;
    case 'X':
        my_putnbr_base((short)va_arg(ap, int), "0123456789ABCDEF", tab, s);
        break;
    }
}

void if9(char *s, int *tab, va_list ap)
{
    switch (s[tab[0]]) {
    case 'h' :
        ifh(s, tab, ap);
        break;
    }
}
