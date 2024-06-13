/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** backspace.c
*/
#include "goyave.h"

void backspace(char **buffer, int *cursor_pos, repo_t *repo)
{
    struct winsize w;

    if (*cursor_pos > 0) {
        memmove(&(*buffer)[*cursor_pos - 1], &(*buffer)[*cursor_pos],
        strlen(*buffer) - *cursor_pos + 1);
        clear_line();
        (*cursor_pos)--;
        if (repo->last_return == 0)
            my_printf("╰─" GREEN("➤") " ");
        else
            my_printf("╰─" RED("➤") " ");
        printf("%s", *buffer);
        move_cursor_left(strlen(*buffer) - *cursor_pos, *buffer);
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        if (w.ws_col == 1) {
            printf("\033[A\r");
            printf("\033[%ldC", strlen(*buffer) % - 2);
        }
    }
}

void delete(char **buffer, int *cursor_pos, repo_t *repo)
{
    if (*cursor_pos < (int)strlen(*buffer)) {
        memmove(&(*buffer)[*cursor_pos], &(*buffer)[*cursor_pos + 1],
        strlen(*buffer) - *cursor_pos + 1);
        clear_line();
        if (repo->last_return == 0)
            my_printf("╰─" GREEN("➤") " ");
        else
            my_printf("╰─" RED("➤") " ");
        printf("%s", *buffer);
        move_cursor_left(strlen(*buffer) - *cursor_pos, *buffer);
    }
}
