/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** print_history.c
*/
#include "goyave.h"

static void print_buf(FILE *file, char *buf, size_t bufsize)
{
    int car = 1;

    while (car != -1) {
        car = getline(&buf, &bufsize, file);
        if (car == -1)
            break;
        my_printf("%s", buf);
    }
}

void print_history(char *pwd)
{
    FILE *file = NULL;
    struct stat sb;
    char *path = NULL;
    char *buf = malloc(sizeof(char) * 2058);
    size_t bufsize = 2058;

    path = get_history_path(pwd);
    stat(path, &sb);
    if (sb.st_size != 0) {
        file = fopen(path, "r");
        print_buf(file, buf, bufsize);
    }
    free(path);
    free(buf);
}
