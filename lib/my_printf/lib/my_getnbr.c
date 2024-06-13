/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** get number from string
*/
#include "../include/my.h"

static int verif(char car)
{
    if (car > '9' || car < '0') {
        return 1;
    }
    return 0;
}

static int is_alpha(char car)
{
    if (car >= 'A' && car <= 'Z' || car >= 'a' && car <= 'z') {
        return 1;
    }
    return 0;
}

static int verification_resultat(long result, int compteur_moins)
{
    if (result > 2147483648 || result < -2147483648) {
        return 0;
    }
    if (compteur_moins % 2 == 1) {
        result = result * -1;
    }
    result = (int)result;
    return result;
}

int my_getnbr(char const *str)
{
    long result = 0;
    int i = 0;
    int nb_chiffre = 0;
    int compteur_moins = 0;

    while (verif(str[i]) && i < my_strlen(str) && !(is_alpha(str[i]))) {
        if (str[i] == '-') {
            compteur_moins ++;
        }
        i ++;
    }
    while (!(verif(str[i])) && !(is_alpha(str[i]))) {
        result = result * 10 + (str[i] - '0');
        nb_chiffre ++;
        i ++;
        if (verif(str[i])) {
            break;
        }
    }
    result = verification_resultat(result, compteur_moins);
}
