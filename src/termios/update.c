/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** udpate.c
*/

#include "goyave.h"


void update(char **buffer, repo_t *repo, int *cursor_pos)
{
    char *cwd_get = getcwd(NULL, 512);

    clear_line();
    if (repo->last_return == 0)
        my_printf("╭─%s\n╰─" GREEN("➤") " ", cwd_get);
    else
        my_printf("╭─%s\n╰─" RED("➤") " ", cwd_get);
    printf("%s", *buffer);
    move_cursor_left(strlen(*buffer) - *cursor_pos, *buffer);
    fflush(stdout);
    free(cwd_get);
}
