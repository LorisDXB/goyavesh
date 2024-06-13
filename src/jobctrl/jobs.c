/*
** EPITECH PROJECT, 2024
** jobs command
** File description:
** for 42sh
*/

#include "goyave.h"

static void show_jobs(jobs_t **head)
{
    jobs_t *tmp = *head;

    while (tmp != NULL) {
        if (tmp->id == 0)
            tmp = tmp->next;
        if (tmp->tty_input == 0)
            jobs_visual(tmp);
        else
            jobs_visual_tty(tmp);
        tmp = tmp->next;
    }
}

static void show_jobs_l(jobs_t **head)
{
    jobs_t *tmp = *head;

    while (tmp != NULL) {
        if (tmp->id == 0)
            tmp = tmp->next;
        if (tmp->tty_input == 0)
            jobs_visual_l(tmp);
        else
            jobs_visual_l_tty(tmp);
        tmp = tmp->next;
    }
}

static int jobs_hub(jobs_t *tmp, int mode)
{
    if (mode == 0) {
        show_jobs(&(tmp));
    }
    if (mode == 1) {
        show_jobs_l(&(tmp));
    }
    return 0;
}

int jobs(repo_t *repo, char **params)
{
    jobs_t *t = repo->jobs;

    if (t->next == NULL)
        return 0;
    if (!params[1]) {
        jobs_hub(t, 0);
    }
    if (params[1] && strcmp(params[1], "-l") == 0) {
        jobs_hub(t, 1);
    }
    return 0;
}
