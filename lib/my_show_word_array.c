/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** emacs
*/

#include <stdlib.h>
#include "my.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    if (tab == NULL)
        return 84;
    while (tab[i] != NULL) {
        my_printf("%s\n", tab[i]);
        i++;
    }
}
