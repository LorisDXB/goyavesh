/*
** EPITECH PROJECT, 2023
** GET NBR
** File description:
** ..
*/
#include "my.h"

int powerten_a(char const *src, int c)
{
    int i = 0;

    while (i < my_strlen(src)) {
        if (src[i] <= '9' && src[i] >= '0')
            c = c * 10;
        if (c != 1 && (src[i] > '9' || src[i] < '0')) {
            i = my_strlen(src);
        }
        i++;
    }
    return (c / 10);
}

int havenbr_a(char const *src, int nbr, int c)
{
    int a = 0;
    int i = 0;

    while (i < my_strlen(src)) {
        if (src[i] <= '9' && src[i] >= '0' && a == 0) {
            nbr = nbr + (src[i] - 48) * c;
            c = c / 10;
        }
        if (src[i] > '9' || src[i] < '0' && src[i] != '-')
            a = 1;
        i++;
    }
    return nbr;
}

int my_getnbr(char const *src)
{
    int nbr = 0;
    int c = 1;
    int i = 0;

    while (src[i] != '\0') {
        if (!(src[i] <= '9' && src[i] >= '0') && src[i] != '-')
            return 0;
        i++;
    }
    if (my_strlen(src) >= 2)
        if (src[0] == '0' || (src[0] == '-' && src[1] == '0'))
            return 0;
    c = powerten_a(src, c);
    nbr = havenbr_a(src, nbr, c);
    if (src[0] == '-')
        nbr = nbr * -1;
    return (nbr);
}
