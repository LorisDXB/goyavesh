/*
** EPITECH PROJECT, 2023
** my_put_hashtag
** File description:
** reproduce behavior of # option
*/
#include "../include/my.h"

int my_put_hashtag(int *tab, int maj, int hexa, int nb)
{
    int i = 2;

    if (nb == 0)
        return 0;
    if (tab[6] != 0 && hexa == 1) {
        if (maj == 1) {
            tab[3] += 2;
            my_putstr("0X");
            return 1;
        } else {
            tab[3] += 2;
            my_putstr("0x");
            return 1;
        }
    } else if (tab[6] != 0 && hexa != 1) {
        my_putstr("0");
        tab[3]++;
    }
}
