/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/


#ifndef MY_H
    #define MY_H
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stddef.h>

char *my_array_to_str(char **tab);
char *int_to_string(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
int my_arrlen(char **a);
char *my_input(char *print);
char **my_str_to_word_array(char *str, char *separators);
char **my_str_to_word_array_keep(char *str, char *separator);
int my_abs(int nb);
int how_many_digits(int nb);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *str);
int my_putchar(int c);
int my_printf(char const *s, ...);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char const *src);
char *my_revstr(char *str);
int my_arrlen2(int **a);
char **my_str_to_word_array_path(char const *str);
char *del_space(char *str);
char **my_array_dup(char **env);
char **my_array_sup_dup(char **env, int index);
int my_show_word_array(char *const *tab);
char *my_strcat(const char *str1, const char *str2);
void free_array(char **arr);

#endif
