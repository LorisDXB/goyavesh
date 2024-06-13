/*
** EPITECH PROJECT, 2024
** jobs_visual
** File description:
** visual
*/

#include "goyave.h"

void jobs_visual_l_tty(jobs_t *tmp)
{
    if (tmp->next != NULL && tmp->next->next != NULL) {
        printf("[%d]   %d Suspended (tty input) %s\n",
                tmp->id, tmp->pid, tmp->name);
        return;
    }
    if (tmp->next != NULL && tmp->next->next == NULL)
        printf("[%d] - %d Suspended (tty input) %s\n",
                tmp->id, tmp->pid, tmp->name);
    else
        printf("[%d] + %d Suspended (tty input) %s\n",
                tmp->id, tmp->pid, tmp->name);
}

void jobs_visual_l(jobs_t *tmp)
{
    if (tmp->next != NULL && tmp->next->next != NULL) {
        printf("[%d]   %d Suspended %s\n", tmp->id, tmp->pid, tmp->name);
        return;
    }
    if (tmp->next != NULL && tmp->next->next == NULL)
        printf("[%d] - %d Suspended %s\n", tmp->id, tmp->pid, tmp->name);
    else
        printf("[%d] + %d Suspended %s\n", tmp->id, tmp->pid, tmp->name);
}

void jobs_visual_tty(jobs_t *tmp)
{
    if (tmp->next != NULL && tmp->next->next != NULL) {
        printf("[%d]    Suspended (tty input) %s\n",
                tmp->id, tmp->name);
        return;
    }
    if (tmp->next != NULL && tmp->next->next == NULL)
        printf("[%d] -  Suspended (tty input) %s\n",
                tmp->id, tmp->name);
    else
        printf("[%d] +  Suspended (tty input) %s\n",
                tmp->id, tmp->name);
}

void jobs_visual(jobs_t *tmp)
{
    if (tmp->next != NULL && tmp->next->next != NULL) {
        printf("[%d]    Suspended %s\n", tmp->id, tmp->name);
        return;
    }
    if (tmp->next != NULL && tmp->next->next == NULL)
        printf("[%d] -  Suspended %s\n", tmp->id, tmp->name);
    else
        printf("[%d] +  Suspended %s\n", tmp->id, tmp->name);
}
