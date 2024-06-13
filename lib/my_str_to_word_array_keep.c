/*
** EPITECH PROJECT, 2023
** bs
** File description:
** str_to_ward_array_keep.c
*/

#include "my.h"

static int my_isseparator(char c, char *separator)
{
    int i = 0;

    while (separator[i] != '\0') {
        if (c == separator[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}

static int count_elements_next(char *separator, char *str, int *i)
{
    while (str[*i] && !my_isseparator(str[*i], separator))
        (*i)++;
}

static int count_elements(char *str, char *separator)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (!my_isseparator(str[i], separator)) {
            count++;
            count_elements_next(separator, str, &i);
        } else {
            count++;
            i++;
        }
    }
    return count;
}

static char *extract_word(char *str, int start, int end)
{
    int startbis = start;
    char *word = malloc(sizeof(char) * (end - start + 1));

    for (int i = 0; start < end; i++) {
        word[i] = str[start];
        start++;
    }
    word[end - startbis] = '\0';
    return word;
}

char **my_str_to_word_array_keep_next(char *str, char *separator,
    char **tab, int i[2])
{
    int word_length = 0;

    if (!my_isseparator(str[i[0]], separator)) {
        while (str[i[0] + word_length] && !my_isseparator(str[i[0] +
        word_length], separator))
            word_length++;
        tab[i[1]] = extract_word(str, i[0], i[0] + word_length);
        (i[1])++;
        if (tab[i[1] - 1] == NULL)
            return NULL;
        i[0] += word_length;
    } else {
        tab[i[1]] = extract_word(str, i[0], i[0] + 1);
        (i[1])++;
        if (tab[i[1] - 1] == NULL)
            return NULL;
        (i[0])++;
    }
}

char **my_str_to_word_array_keep(char *str, char *separator)
{
    int size = count_elements(str, separator);
    int i[2] = {0, 0};
    char **tab = malloc(sizeof(char *) * (size + 1));

    if (tab == NULL)
        return NULL;
    while (str[i[0]] != '\0') {
        my_str_to_word_array_keep_next(str, separator, tab, i);
    }
    tab[size] = NULL;
    return tab;
}
