/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Displays, one-by-one, the characters of a string.
*/

#include "../include/my.h"

static void print_space_front(int cpt, int *tab)
{
    if (tab[1] - cpt > 0 && tab[8] == 0 && tab[7] == 0) {
        while (tab[1] - cpt > 0) {
            my_putchar(' ');
            tab[1]--;
        }
    }
    if (tab[1] - cpt > 0 && tab[8] == 0 && tab[7] != 0) {
        while (tab[1] - cpt > 0) {
            my_putchar('0');
            tab[1]--;
        }
    }
}

static void print_space_back(int cpt, int *tab)
{
    if (tab[1] - cpt > 0 && tab[8] != 0 && tab[7] == 0) {
        while (tab[1] - cpt > 0) {
            my_putchar(' ');
            tab[1]--;
        }
    }
    if (tab[1] - cpt > 0 && tab[8] != 0 && tab[7] == 0) {
        while (tab[1] - cpt > 0) {
            my_putchar('0');
            tab[1]--;
        }
    }
}

int my_putstrflag(char const *str, int *tab)
{
    int i = 0;

    print_space_front(my_strlen(str) - tab[1], tab);
    if (tab[4] == 0)
        my_putstr(str);
    else {
        while (str[i] != '\0' && tab[2] != i) {
            my_putchar(str[i]);
            i++;
        }
    }
    print_space_back(my_strlen(str) - tab[1], tab);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i ++;
    }
}
