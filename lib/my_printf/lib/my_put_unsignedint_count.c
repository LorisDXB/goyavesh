/*
** EPITECH PROJECT, 2023
** my_putsignedint
** File description:
** emacs
*/
#include "../include/my.h"

static int my_recursive(unsigned int n, int *ptr)
{
    if (n < 0) {
        my_recursive(4294967295 + n, ptr);
    }
    if (n >= 10) {
        my_recursive(n / 10, ptr);
        *ptr += 1;
    }
    if (n < 10) {
        *ptr += 1;
    }
}

int my_put_unsignedint_count(unsigned int n)
{
    int count = 0;
    int *ptr = &count;

    my_recursive(n, ptr);
    return *ptr;
}
