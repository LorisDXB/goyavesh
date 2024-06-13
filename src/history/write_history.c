/*
** EPITECH PROJECT, 2023
** 42sh_test
** File description:
** history.c
*/
#include "goyave.h"

static char *arr_to_str(char **arr)
{
    char *new = NULL;
    int size = 0;

    if (my_arrlen(arr) > 1) {
        for (int i = 0; arr[i]; i++)
            size += strlen(arr[i]) + 1;
        new = calloc(sizeof(char), size + 1);
        new[size] = '\0';
        new = strcpy(new, arr[0]);
        for (int i = 1; arr[i]; i++) {
            new = strcat(new, " ");
            new = strcat(new, arr[i]);
        }
        return new;
    } else {
        return arr[0];
    }
}

static void file_empty(FILE *file, char *cmd)
{
    char *nb_char = NULL;
    char **tab = my_str_to_word_array(cmd, " ");

    nb_char = int_to_string(1);
    fwrite(nb_char, strlen(nb_char), 1, file);
    fwrite(" : ", 3, 1, file);
    fwrite(cmd, strlen(cmd), 1, file);
    fwrite("\n", 1, 1, file);
    free_array(tab);
    free(nb_char);
}

static void file_exist_writing(FILE *file, char *cmd, char *nb_char,
    repo_t *repo)
{
    char **tab = my_str_to_word_array(cmd, " ");
    char *to_write = NULL;
    char **history = history_to_array(repo);
    int nb = atoi(cmd + 1);

    if (cmd[0] == '!' && (nb > my_arrlen(history) || nb == 0 ||
    (nb < 0 && nb * -1 > my_arrlen(history) - 1)))
        return;
    for (int i = 0; tab[i]; i++) {
        tab = compare_both_history(tab, i, repo, 0);
    }
    to_write = arr_to_str(tab);
    fwrite(nb_char, strlen(nb_char), 1, file);
    fwrite(" : ", 3, 1, file);
    fwrite(to_write, strlen(to_write), 1, file);
    fwrite("\n", 1, 1, file);
    if (my_arrlen(tab) > 1)
        free(to_write);
    free_array(history);
    free_array(tab);
}

static void file_exist(FILE *file, char *cmd, repo_t *repo)
{
    size_t bufsize = 2058;
    char *buf = NULL;
    char *buf_tmp = malloc(sizeof(char) * 2058);
    char *nb_char = NULL;
    int car = 0;
    int nb_int = 0;

    while (car != -1) {
        buf = buf_tmp;
        car = getline(&buf_tmp, &bufsize, file);
        if (car != -1)
            buf_tmp[car - 1] = '\0';
    }
    nb_int = atoi(buf);
    nb_char = int_to_string(nb_int + 1);
    file_exist_writing(file, cmd, nb_char, repo);
    free(nb_char);
    free(buf_tmp);
}

char *get_history_path(char *first_pwd)
{
    char *new_path = malloc(sizeof(char) * (strlen(first_pwd) +
    strlen("/.goyave_history") + 1));

    if (!new_path) {
        exit(84);
    }
    new_path = strcpy(new_path, first_pwd);
    new_path = strcat(new_path, "/.goyave_history");
    return new_path;
}

void write_history(char *cmd, char *first_pwd, repo_t *repo)
{
    struct stat sb;
    FILE *file = NULL;
    char *path = NULL;

    if (strlen(cmd) == 0 || strcmp(cmd, "\n") == 0)
        return;
    path = get_history_path(first_pwd);
    file = fopen(path, "a+");
    if (!file)
        exit(84);
    stat(path, &sb);
    if (sb.st_size == 0) {
        file_empty(file, cmd);
    } else {
        file_exist(file, cmd, repo);
    }
    fclose(file);
    free(path);
}

char **history_to_array(repo_t *repo)
{
    struct stat sb;
    char **tab = NULL;
    char *path = NULL;
    char *buf = NULL;
    int fd = 0;

    path = get_history_path(repo->pwd);
    stat(path, &sb);
    if (sb.st_size != 0) {
        buf = malloc(sizeof(char) * (sb.st_size + 1));
        fd = open(path, O_RDONLY);
        read(fd, buf, sb.st_size);
        buf[sb.st_size] = '\0';
        tab = my_str_to_word_array(buf, "\n");
        free(buf);
    }
    free(path);
    return tab;
}
