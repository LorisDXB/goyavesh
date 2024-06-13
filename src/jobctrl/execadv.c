/*
** EPITECH PROJECT, 2024
** loris
** File description:
** loris
*/

#include "goyave.h"

static int get_jobid(jobs_t **job)
{
    jobs_t *tmp = *job;
    int ct = 0;

    while (tmp->next != NULL) {
        ct++;
        tmp = tmp->next;
    }
    return ct;
}

void add_node(jobs_t **job, int pgid, char *name, int tty_input)
{
    jobs_t *toadd = jobs_init(pgid, name, get_jobid(job) + 1, tty_input);
    jobs_t *tmp = (*job);

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = toadd;
    toadd->next = NULL;
}

void show_list(jobs_t **job)
{
    jobs_t *tmp = (*job);

    while (tmp != NULL) {
        if (tmp->pid == -20) {
            tmp = tmp->next;
        }
        tmp = tmp->next;
    }
}

jobs_t *execadv(repo_t *repo, int id, char *name, int tty_input)
{
    add_node(&repo->jobs, id, name, tty_input);
    return NULL;
}
