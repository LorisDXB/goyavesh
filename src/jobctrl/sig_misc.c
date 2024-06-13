/*
** EPITECH PROJECT, 2024
** sig reroute
** File description:
** for 42sh
*/

#include "goyave.h"

static int get_lastpid(jobs_t **arr)
{
    int i = 0;

    while (arr[i + 1] != NULL) {
        i++;
    }
    return arr[i]->pid;
}

int sig_reroute(jobs_t **arr, repo_t *repo)
{
    return 0;
}
