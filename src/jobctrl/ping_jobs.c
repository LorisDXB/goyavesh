/*
** EPITECH PROJECT, 2024
** ping jobs
** File description:
** ping jobs
*/

#include "goyave.h"

int del_assist(jobs_t *temp, jobs_t *prev, jobs_t **head, int pid)
{
    if (temp->pid == pid) {
        if (prev == NULL) {
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }
        if (temp != NULL) {
            free(temp);
            return 1;
        }
    }
    return 0;
}

int del(jobs_t **head, int pid)
{
    jobs_t *temp = *head;
    jobs_t *prev = NULL;

    while (temp != NULL) {
        if (del_assist(temp, prev, head, pid) == 1)
            return 1;
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

int ping_jobs(repo_t *repo)
{
    jobs_t *tmp = repo->jobs;
    int status = 0;

    while (tmp != NULL) {
        status = kill((pid_t)tmp->pid, 0);
        if (status != 0 && tmp->pid != -20 &&
            del(&repo->jobs, tmp->pid) == 1) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
