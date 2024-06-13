/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** print_char.c
*/
#include "goyave.h"

void clear_line(void)
{
    printf("\033[K\r");
    printf("\033[K\r");
    printf("\033[B\r");
    printf("\033[D\r");
    printf("\033[K\r");
    printf("\033[u\r");
    printf("\033[K\r");
    fflush(stdout);
}

void move_cursor_left(int n, char *buffer)
{
    struct winsize w;
    int len = strlen(buffer) + 4;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    if (w.ws_col <= len && n > len % w.ws_col) {
        if (w.ws_col != len)
            printf("\033[%dA", ((n - (len % w.ws_col)) / w.ws_col) + 1);
        printf("\033[%dC", w.ws_col);
        if ((((n - (len % w.ws_col)) % w.ws_col)) > 1)
            printf("\033[%dD", ((n - (len % w.ws_col)) % w.ws_col) - 1);
    }
    if (!(w.ws_col <= len && n > len % w.ws_col)) {
        if (n != 0) {
            printf("\033[%dD", n);
        }
    }
    fflush(stdout);
}

void print_char(char **buffer, int *cursor_pos, repo_t *repo, char c)
{
    char *cwd_get = getcwd(NULL, 512);

    memmove(&(*buffer)[(*cursor_pos) + 1], &(*buffer)[*cursor_pos],
    strlen(*buffer) - *cursor_pos + 1);
    (*buffer)[*cursor_pos] = c;
    (*cursor_pos)++;
    clear_line();
    if (repo->last_return == 0)
        my_printf("╰─" GREEN("➤") " ");
    else
        my_printf("╰─" RED("➤") " ");
    printf("%s", *buffer);
    free(cwd_get);
    move_cursor_left(strlen(*buffer) - *cursor_pos, *buffer);
}
