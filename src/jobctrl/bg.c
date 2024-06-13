/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** bg.c
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

static void print_bg(jobs_t *j)
{
    if (j->tty_input == 1)
        printf("[%d] %s &\n[%d] Running %s\n", j->id,
        j->name, j->id, j->name);
    if (j->tty_input == 0)
        printf("[%d] %s %d&\n", j->id, j->name, j->tty_input);
}

static int exec_bg_next(jobs_t *j, repo_t *repo, char **params)
{
    while (j != NULL) {
        if ((params[1] == NULL && j != NULL) || (params[1][0] == '%' &&
        j->id == atoi(params[1] + 1)) || j->pid == atoi(params[1]) ||
        (j->name && strcmp(min(j->name), min(params[1])) == 0)) {
            set_termios_echo_mod(repo);
            print_bg(j);
            return 0;
        }
        j = j->next;
    }
    set_termios_echo_mod(repo);
    return 0;
}

int exec_bg(repo_t *repo, char **params)
{
    jobs_t *j = repo->jobs;

    if (j != NULL)
        j = j->next;
    set_termios_canon_mod(repo);
    if (len_array(params) > 2) {
        set_termios_echo_mod(repo);
        write(2, "fg [job_id]\n", 8);
        return 1;
    }
    return exec_bg_next(j, repo, params);
}
