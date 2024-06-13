/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** fg.c
*/

#include "goyave.h"

static char *min(char *str)
{
    char *ret = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ret[i] = str[i] + 32;
        } else {
            ret[i] = str[i];
        }
    }
    ret[i] = '\0';
    return ret;
}

static int exec_fg_next(jobs_t *j, repo_t *repo, char **params)
{
    while (j != NULL) {
        if ((params[1] == NULL && j->next == NULL) ||
        (params[1] && params[1][0] == '%' && j->id == atoi(params[1] + 1)) ||
        (params[1] && j->pid == atoi(params[1])) ||
        (params[1] && j->name && strcmp(min(j->name), min(params[1])) == 0)) {
            kill(j->pid, SIGCONT);
            exec_ext(repo, j->pid, params[1], 0);
            del(&(repo->jobs), j->pid);
            set_termios_echo_mod(repo);
            return 0;
        }
        j = j->next;
    }
    set_termios_echo_mod(repo);
    return 0;
}

int exec_fg(repo_t *repo, char **params)
{
    jobs_t *j = repo->jobs;

    if (j != NULL)
        j = j->next;
    set_termios_canon_mod(repo);
    if (len_array(params) > 2) {
        write(2, "fg [job_id]\n", 8);
        set_termios_echo_mod(repo);
        return 1;
    }
    return exec_fg_next(j, repo, params);
}
