/*
** EPITECH PROJECT, 2023
** my_putexp.c
** File description:
** emacs
*/
#include "../include/my.h"

static int print0_count(int i, int *tab)
{
    int cpt = 0;

    if (i < 10) {
        cpt++;
    }
    return cpt;
}

int my_putexpnegative_count(float decimal_first, int k,
    int *tab, int etat_flag)
{
    int i = 0;
    int cpt = 0;

    while (decimal_first < 1) {
        decimal_first *= 10;
        i++;
    }
    if (etat_flag == 2)
        cpt += my_putfloat_g(decimal_first, tab);
    else
        cpt += my_putfloat_count(decimal_first, tab);
    cpt += 2;
    cpt += print0_count(i, tab);
    cpt += count_digit(i);
    return cpt;
}

int my_putexppositive_count(float decimal_first, int decimal,
    int *tab, int etat_flag)
{
    int i = 0;
    int cpt = 0;

    while (decimal_first >= 10) {
        decimal_first /= 10;
        i++;
    }
    if (etat_flag == 2)
        cpt += my_putfloat_g_count(decimal_first, tab);
    else
        cpt += my_putfloat_count(decimal_first, tab);
    cpt += 2;
    if (i < 10) {
        cpt++;
    }
    cpt += count_digit(i);
    return cpt;
}

int my_putexp_count(float decimal_first, int etat_flag, int *tab, int decimal)
{
    int cpt = 0;

    if (decimal_first == 0) {
        cpt += 12;
        return cpt;
    }
    if (decimal_first < 0) {
        decimal_first = -decimal_first;
        cpt++;
    }
    if (decimal_first >= 1) {
        cpt += my_putexppositive_count(decimal_first, etat_flag, tab, decimal);
    } else if (decimal_first < 1)
        cpt += my_putexpnegative_count(decimal_first, etat_flag, tab, decimal);
    return cpt;
}
