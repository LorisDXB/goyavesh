/*
** EPITECH PROJECT, 2023
** my puthchar
** File description:
** ..
*/

#include <unistd.h>
#include "my.h"

int my_putchar(int c)
{
    write(1, &c, 1);
    return 0;
}
