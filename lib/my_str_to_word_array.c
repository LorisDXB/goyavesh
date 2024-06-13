/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** emacs
*/

#include <stdio.h>
#include <stdlib.h>

static int my_isalnum(char c, char *separator)
{
    int i = 0;

    while (separator[i] != '\0') {
        if (c == separator[i]) {
            return 0;
        }
        i++;
    }
    if (c == '\0')
        return 0;
    return 1;
}

static int count_word_next(char const *str, int i, char *separator)
{
    while (my_isalnum(str[i], separator)) {
        i++;
    }
    return i;
}

static int count_word(char const *str, char *separator)
{
    int i = 0;
    int cpt_word = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        if (my_isalnum(str[i], separator)) {
            i = count_word_next(str, i, separator);
            cpt_word++;
        }
        if (str[i] == '\0') {
            return cpt_word;
        }
        i++;
    }
    return cpt_word;
}

static int alloc_tab_char_next(char const *str, char *separator,
    int *len_word, int *i)
{
    while (my_isalnum(str[*i], separator)) {
        (*i)++;
        (*len_word)++;
    }
}

static void alloc_tab_char(char const *str, char **tab, char *separator)
{
    int i = 0;
    int cpt_word = 0;
    int len_word = 0;

    while (str[i] != '\0') {
        if (my_isalnum(str[i], separator)) {
            len_word = 0;
            alloc_tab_char_next(str, separator, &len_word, &i);
            tab[cpt_word] = malloc(sizeof(char) * (len_word + 1));
            cpt_word++;
        }
        if (str[i] == '\0')
            return;
        i++;
    }
}

static void my_str_to_word_array_next(char const *str, int *tabbis,
    char **tab, char *separator)
{
    while (my_isalnum(str[tabbis[2]], separator)) {
        tab[tabbis[0]][tabbis[1]] = str[tabbis[2]];
        tabbis[2]++;
        tabbis[1]++;
    }
    tab[tabbis[0]][tabbis[1]] = '\0';
    tabbis[0]++;
}

char **my_str_to_word_array(char const *str, char *separator)
{
    char **tab = malloc(sizeof(char *) * (count_word(str, separator) + 1));
    int cpt_word = 0;
    int len_word = 0;
    int i = 0;
    int tabbis[3] = {0, 0, 0};

    alloc_tab_char(str, tab, separator);
    while (str[tabbis[2]] != '\0') {
        if (my_isalnum(str[tabbis[2]], separator)) {
            tabbis[1] = 0;
            my_str_to_word_array_next(str, tabbis, tab, separator);
        }
        if (str[tabbis[2]] == '\0')
            break;
        tabbis[2]++;
    }
    tab[tabbis[0]] = NULL;
    return tab;
}
