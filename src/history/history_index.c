/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** history_index.c
*/
#include "goyave.h"


void history_ind_arrow_up(repo_t *repo, char **tab)
{
    if (repo->last_history_pos == -1) {
        repo->last_history_pos = my_arrlen(tab) - 1;
    } else {
        if (repo->last_history_pos >= 1) {
            repo->last_history_pos -= 1;
        }
    }
}

void history_ind_arrow_down(repo_t *repo, char **tab)
{
    if (repo->last_history_pos == my_arrlen(tab) - 1) {
        repo->last_history_pos = -1;
    }
    if (repo->last_history_pos != -1) {
        if (repo->last_history_pos <= my_arrlen(tab) - 2) {
            repo->last_history_pos += 1;
        }
    }
}
