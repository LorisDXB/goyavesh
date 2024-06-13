/*
** EPITECH PROJECT, 2023
** my_put_error
** File description:
** afficher la sortie de strerror(errno)
*/
#include <errno.h>
#include "../include/my.h"
#include "../include/error.h"

int my_put_error(int error_number, int *tab)
{
    const char *chaine;

    if (error_number < 41 && error_number > 0) {
        tab[3] += my_strlen(erreur[error_number - 2]);
        my_putstr(erreur[error_number - 2]);
    }
    if (error_number > 41 && error_number < 58) {
        tab[3] += my_strlen(erreur[error_number - 3]);
        my_putstr(erreur[error_number - 3]);
    }
    if (error_number > 58 && error_number <= 133) {
        tab[3] += my_strlen(erreur[error_number - 4]);
        my_putstr(erreur[error_number - 4]);
    }
    if (error_number == 0) {
        tab[3] += my_strlen("Success");
        my_putstr("Success");
    }
    return -1;
}
