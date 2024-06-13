/*
** EPITECH PROJECT, 2023
** my str cat
** File description:
** ..
*/
#include "my.h"

char *my_strcat(const char *str1, const char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int j = 0;
    int i = 0;
    char *result = malloc(sizeof(char) * (len1 + len2 + 1));

    if (result == NULL)
        return NULL;
    while (i < len1) {
        result[i] = str1[i];
        i++;
    }
    while (j < len2) {
        result[len1 + j] = str2[j];
        j++;
    }
    result[len1 + len2] = '\0';
    return result;
}

char *my_strcat_with_space(const char *str1, const char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int j = 0;
    int i = 0;
    char *result = malloc(sizeof(char) * (len1 + len2 + 3));

    if (result == NULL)
        return NULL;
    while (i < len1) {
        result[i] = str1[i];
        i++;
    }
    result[i] = ' ';
    while (j < len2) {
        result[len1 + j + 1] = str2[j];
        j++;
    }
    result[len1 + j + 1] = '/';
    result[len1 + len2 + 2] = '\0';
    return result;
}
