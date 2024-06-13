/*
** EPITECH PROJECT, 2023
** is_flag
** File description:
** return 1 if char is a printf flag
*/
#include "../include/my.h"

int is_flag(char const car)
{
    return (car == 'd' || car == 'i' || car == 'o' || car == 'u' ||
            car == 'x' || car == 'X' || car == 'e' || car == 'E' ||
            car == 'f' || car == 'F' || car == 'g' || car == 'G' ||
            car == 'a' || car == 'A' || car == 'c' || car == 's' ||
            car == 'p' || car == 'm' || car == '%');
}
