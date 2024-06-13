/*
** EPITECH PROJECT, 2024
** GoyaveSh_mirror
** File description:
** goyaverc
*/

#include "goyave.h"


char **get_line_rc(void)
{
    FILE *file = fopen(GOYAVE_PATH, "a+");
    char *buffer = NULL;
    char **line_file = malloc(sizeof(char *) * MAXLINE_RC);
    int i = 0;
    size_t len = 0;
    size_t line_len = 0;

    while (i < MAXLINE_RC && getline(&buffer, &len, file) != -1) {
        line_file[i] = strdup(buffer);
        line_len = strlen(line_file[i]);
        if (len > 0 && line_file[i][line_len - 1] == '\n')
            line_file[i][line_len - 1] = '\0';
        line_file[i][line_len] = '\0';
        i++;
    }
    line_file[i] = NULL;
    free(buffer);
    fclose(file);
    return line_file;
}

rc_file_t *get_alias_rc(rc_file_t *file)
{
    int a = 0;
    char **len_a = NULL;

    file->alias = malloc(sizeof(char *) * (my_arrlen(file->line_file) + 1));
    for (int i = 0; file->line_file[i]; i++) {
        len_a = my_str_to_word_array(file->line_file[i], " =");
        if (my_strncmp("alias", file->line_file[i], 4) == 0
        && my_arrlen(len_a) >= 3) {
            file->alias[a] = strdup(file->line_file[i]);
            a++;
        }
        free_array(len_a);
    }
    file->alias[a] = NULL;
    return file;
}

static char **compare_both_alias(char *line, char **str_a, int b)
{
    char **alias_value = my_str_to_word_array(line, "'");
    char **temp = my_str_to_word_array(line, " =\0");

    if (my_arrlen(alias_value) != 2)
        exit(84);
    if (strcmp(temp[1], str_a[b]) == 0) {
        free(str_a[b]);
        str_a[b] = strdup(alias_value[1]);
    }
    free_array(temp);
    free_array(alias_value);
    return str_a;
}

static char *my_strcat_not_malloc(char *dest, char const *src)
{
    int j = my_strlen(dest);

    for (int i = 0; src[i]; i++) {
        dest[j] = src[i];
        j++;
    }
    dest[j] = '\0';
    return dest;
}

static char *my_strcpy_not_malloc(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *str_cat_command(char **str_a)
{
    int size = 0;
    char *send = NULL;

    for (int i = 0; str_a[i]; i++)
        size += strlen(str_a[i]) + 1;
    send = malloc(sizeof(char) * (size + 1));
    send[size - 1] = '\0';
    if (str_a[0] == NULL)
        return send;
    send = my_strcpy_not_malloc(send, str_a[0]);
    size += strlen(str_a[0]);
    if (str_a[1])
        send = my_strcat_not_malloc(send, " ");
    for (int i = 1; str_a[i]; i++) {
        send = my_strcat_not_malloc(send, str_a[i]);
        send = my_strcat_not_malloc(send, " ");
    }
    free_array(str_a);
    return send;
}

char *format_with_rc(char *str, rc_file_t *file, repo_t *repo)
{
    char **str_a = my_str_to_word_array(str, " ");

    for (int b = 0; str_a[b]; b++) {
        for (int i = 0; file->alias[i]; i++) {
            str_a = compare_both_alias(file->alias[i], str_a, b);
        }
        str_a = compare_both_history(str_a, b, repo, 1);
    }
    return some_backtick(repo, str_cat_command(str_a));
}

rc_file_t *init_rc_file(void)
{
    rc_file_t *file = malloc(sizeof(rc_file_t));

    file->line_file = get_line_rc();
    file = get_alias_rc(file);
    return file;
}
