/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** change_status.c
*/

#include "goyave.h"

void update_status(jobs_t *j, int pid)
{
    jobs_t *temp = j;

    while (temp != NULL) {
        if (temp->pid == pid)
            temp->state = BG;
        temp = temp->next;
    }
}
