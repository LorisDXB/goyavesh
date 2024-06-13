/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** arrow.c
*/
#include "goyave.h"

int get_cmd_start(char *str)
{
    int i = 0;

    for (i = 0; str[i] && str[i] != ':'; i++);
    return i + 2;
}

static void arrow_down(char **buffer, int *cursor_pos, repo_t *repo)
{
    char **tab = history_to_array(repo);
    int start = 0;

    history_ind_arrow_down(repo, tab);
    if (repo->last_history_pos == -1) {
        clear_line();
        memset(*buffer, '\0', strlen(*buffer));
        *cursor_pos = 0;
    } else {
        start = get_cmd_start(tab[repo->last_history_pos]);
        clear_line();
        memset(*buffer, '\0', strlen(*buffer));
        strcpy(*buffer, tab[repo->last_history_pos] + start);
        *cursor_pos = strlen(tab[repo->last_history_pos] + start);
        clear_line();
    }
    free_array(tab);
}

static void arrow_up_down(char **buffer, int *cursor_pos, repo_t *repo,
    char seq[3])
{
    char **tab = NULL;
    int start = 0;

    if (seq[1] == 'A') {
        tab = history_to_array(repo);
        history_ind_arrow_up(repo, tab);
        start = get_cmd_start(tab[repo->last_history_pos]);
        clear_line();
        memset(*buffer, '\0', strlen(*buffer));
        strcpy(*buffer, tab[repo->last_history_pos] + start);
        *cursor_pos = strlen(tab[repo->last_history_pos] + start);
        clear_line();
        free_array(tab);
    }
    if (seq[1] == 'B') {
        arrow_down(buffer, cursor_pos, repo);
    }
}

static void arrow_next(int *cursor_pos, char seq[3], char **buffer,
    repo_t *repo)
{
    char *cwd_get = getcwd(NULL, 512);

    if (seq[1] == 'C' && (*cursor_pos < (int)strlen(*buffer)))
        (*cursor_pos)++;
    if (seq[1] == 'D' && (*cursor_pos > 0))
        (*cursor_pos)--;
    arrow_up_down(buffer, cursor_pos, repo, seq);
    clear_line();
    if (repo->last_return == 0)
        my_printf("╰─" GREEN("➤") " ", cwd_get);
    else
        my_printf("╰─" RED("➤") " ", cwd_get);
    printf("%s", *buffer);
    move_cursor_left(strlen(*buffer) - *cursor_pos, *buffer);
    free(cwd_get);
}

void arrow(char **buffer, int *cursor_pos, repo_t *repo)
{
    char seq[3];
    char *cwd_get = getcwd(NULL, 512);

    if (read(STDIN_FILENO, &seq[0], 1) != 1 ||
    read(STDIN_FILENO, &seq[1], 1) != 1)
        return;
    if (seq[0] == '[') {
        arrow_next(cursor_pos, seq, buffer, repo);
    }
    free(cwd_get);
}
