/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** prototype of all lib
*/

#include <stdarg.h>

#ifndef MY_
    #define MY_

int my_putnbr_base_count(unsigned int nbr, char const *base,
    char *s, int *tab);
int my_putnbr_base_flag(unsigned int nbr, char const *base, int *tab, char *s);
int my_putfloat_flag(double decimal_first, int *tab);
int my_putfloat_count(double decimal_first, int *tab);
int my_putstrflag(char const *str, int *tab);
void my_putcharflag(char c, int *tab);
void my_putnbrflag(int nb, int *tab);
int my_putfloat_g_count(double decimal_first, int *tab);
int my_putexp_count(float decimal_first, int etat_flag, int *tab, int decimal);
int my_putfloat_g(double decimal_first, int *tab);
int merge_count(double decimal_first, int k, int *tab);
int my_putfloat_count(double decimal_first, int *tab);
void my_put_space(char *s, int *tab, va_list list);
void if9(char *s, int *tab, va_list ap);
int merge(double decimal_first, int k, int *tab);
int my_putfloat_g(double decimal_first, int *tab);
int is_flag(char const car);
int my_putfloat(double decimal_first, int *tab);
int my_putexp(float decimal_first, int k, int *tab, int j);
int my_printf(char *s, ...);
void switch_next(char *s, int *tab, va_list ap);
int my_put_unsignedint(unsigned int nb, int *tab);
void my_putchar(char c);
void my_putnbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int count_digit(int nb);
int my_getnbr(char const *str);
int my_putnbr_base(unsigned int nbr, char const *base, int *tab, char *s);
int my_put_error(int error_number, int *tab);
int my_put_hashtag(int *tab, int maj, int hexa, int nb);

#endif
