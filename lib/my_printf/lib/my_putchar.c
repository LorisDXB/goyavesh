/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** display a char
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

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

void my_putcharflag(char c, int *tab)
{
    print_space_front(1, tab);
    write(1, &c, 1);
    print_space_back(1, tab);
}
