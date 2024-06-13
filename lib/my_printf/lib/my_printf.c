/*
** EPITECH PROJECT, 2023
** disp_stdarg.c
** File description:
** emacs
*/

#include <stdio.h>
#include <stdarg.h>
#include "../include/my.h"

//tab[0] = i_global || tab[1,2] = digits% || tab[3] = cpt ||
//tab[4] = nothing || tab[5] = nothing
//tab[6] = '#' || tab[7] = '0' || tab[8] = '-' || tab[9] = ' '
//tab[10] = '+'

static int verif_space(char *s, int *tab)
{
    if (s[tab[0]] == ' ') {
        tab[0]++;
        my_putchar(' ');
    }
    while (s[tab[0]] == ' ') {
        tab[0]++;
        tab[3]--;
    }
}

static int verif_flag_characters2(char *s, int *tab)
{
    switch (s[tab[0]]) {
    case '#':
        tab[6]++;
        break;
    case '0':
        tab[7]++;
        break;
    case '-':
        tab[8]++;
        break;
    case ' ':
        tab[9]++;
        break;
    case '+':
        tab[10]++;
        break;
    }
    tab[0]++;
}

static int verif_flag_characters(char *s, int *tab)
{
    int i = 6;

    while (i != 11) {
        tab[i] = 0;
        i++;
    }
    tab[0]++;
    while (s[tab[0]] == '0' || s[tab[0]] == '#' || s[tab[0]] == ' ' ||
        s[tab[0]] == '-' || s[tab[0]] == '+') {
        verif_flag_characters2(s, tab);
    }
    return 0;
}

static int verif_digit(char *s, int *tab, va_list ap)
{
    tab[1] = 0;
    tab[2] = 0;
    tab[4] = 0;
    while ((s[tab[0]] >= '0' && s[tab[0]] <= '9')) {
        tab[1] = tab[1] * 10 + (s[tab[0]] - '0');
        tab[0]++;
        tab[3]--;
    }
    if (s[tab[0]] == '.') {
        tab[0]++;
        tab[3]--;
        if (s[tab[0]] == '0')
            return 0;
        while (s[tab[0]] >= '0' && s[tab[0]] <= '9') {
            tab[2] = tab[2] * 10 + (s[tab[0]] - '0');
            tab[0]++;
            tab[4]++;
            tab[3]--;
        }
    }
}

static int verif(char *s, int *tab, va_list ap)
{
    if (s[tab[0]] != '%'){
        my_putchar(s[tab[0]]);
        tab[3]++;
    } else if (s[tab[0]+1] == '%') {
        my_putchar(s[tab[0]]);
        tab[3]++;
    }
    if (s[tab[0]] == '%') {
        verif_flag_characters(s, tab);
        verif_digit(s, tab, ap);
        tab[3] += -2;
        switch_next(s, tab, ap);
    }
}

int my_printf(char *s, ...)
{
    va_list ap;
    int i = 0;
    int cpt = 0;
    int tab[11] = {i, 0, 0, cpt, 0, 0, 0, 0, 0, 0, 0};

    if (s == NULL)
        return 84;
    va_start(ap, s);
    while (s[tab[0]] != '\0') {
        verif(s, tab, ap);
        tab[0]++;
    }
    va_end(ap);
    return cpt;
}
