/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** get_all_prog.c
*/

#include "goyave.h"

static void condition(char *buff, char *str, char **tab, int *count)
{
    if (my_strncmp(buff, str, strlen(buff) - 1) == 0) {
        tab[*count] = strdup(str);
        *count += 1;
    }
}

int fill_tab(char **tab, char *path, char *buff)
{
    int count = 0;
    char *str = NULL;
    struct dirent *entry;
    DIR *dir;

    dir = opendir(path);
    if (dir == NULL)
        exit(84);
    entry = readdir(dir);
    while (entry != NULL) {
        str = strdup(entry->d_name);
        condition(buff, str, tab, &count);
        free(str);
        entry = readdir(dir);
    }
    tab[count] = NULL;
    closedir(dir);
    return count;
}

char *get_all_prog(char *path, char *buff)
{
    char **tab = calloc(sizeof(char *), 1459);
    char **buffer = my_str_to_word_array_keep(buff, " \n\0");

    if (buffer[0] == NULL)
        return "";
    fill_tab(tab, path, buffer[my_arrlen(buffer) -1]);
    if (len_array(tab) == 1) {
        buffer[my_arrlen(buffer) - 1] = my_strcat(buffer[my_arrlen(buffer) - 1]
        , tab[0] + strlen(buffer[my_arrlen(buffer) - 1]));
        return my_array_to_str(buffer);
    }
    printf("\n");
    my_show_word_array(tab);
    for (int i = 0; i != 1459; i++)
        free(tab[i]);
    free(tab);
    return my_array_to_str(buffer);
}
