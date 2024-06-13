/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** line_editing_ctrl.c
*/

#include "goyave.h"

void go_all_left(char **buffer, int *cursor_pos, repo_t *repo)
{
    char *cwd_get = getcwd(NULL, 512);

    *cursor_pos = 0;
    clear_line();
    if (repo->last_return == 0)
        my_printf("╰─" GREEN("➤") " ");
    else
        my_printf("╰─" RED("➤") " ");
    printf("%s", *buffer);
    free(cwd_get);
    move_cursor_left(strlen(*buffer) - *cursor_pos, *buffer);
}

void clear_end_of_line(char **buffer, int *cursor_pos, repo_t *repo)
{
    char *cwd_get = getcwd(NULL, 512);

    repo->copy = strdup(*buffer + *cursor_pos);
    *buffer = my_strncpy(*buffer, *buffer, *cursor_pos);
    clear_line();
    if (repo->last_return == 0)
        my_printf("╰─" GREEN("➤") " ");
    else
        my_printf("╰─" RED("➤") " ");
    printf("%s", *buffer);
    free(cwd_get);
    move_cursor_left(strlen(*buffer) - *cursor_pos, *buffer);
}

void past_line(char **buffer, int *cursor_pos, repo_t *repo)
{
    char *cwd_get = getcwd(NULL, 512);

    if (repo->copy != NULL)
        *buffer = strcat(*buffer, repo->copy);
    clear_line();
    if (repo->last_return == 0)
        my_printf("╰─" GREEN("➤") " ");
    else
        my_printf("╰─" RED("➤") " ");
    printf("%s", *buffer);
    free(cwd_get);
    move_cursor_left(strlen(*buffer) - *cursor_pos, *buffer);
}
