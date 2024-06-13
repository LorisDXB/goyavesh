/*
** EPITECH PROJECT, 2024
** init jobs
** File description:
** for 42sh
*/

#include "goyave.h"

jobs_t *jobs_init(int pgid, char *name, int idp, int tty_input)
{
    jobs_t *init = malloc(sizeof(jobs_t));

    if (init == NULL)
        return NULL;
    init->pid = pgid;
    init->state = FG;
    init->tty_input = tty_input;
    if (name != NULL) {
        init->name = strdup(name);
    } else {
        init->name = NULL;
    }
    init->id = idp;
    init->next = NULL;
    if (tty_input == 0)
        printf("Suspended\n");
    else if (idp != 0)
        printf("[%d] %d\n", idp, pgid);
    return init;
}
