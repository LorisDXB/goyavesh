/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** local_vars.h
*/

#ifndef JOB_CONTROL_H_
    #define JOB_CONTROL_H_
    #include "struct.h"
    #include "goyave.h"
    #include <sys/wait.h>
    #include <string.h>
    #include <signal.h>

extern int sigrec;

enum states {
    FG = 1,
    BG = 2,
};

typedef struct jobs_s {
    int pid;
    enum states state;
    int id;
    char *name;
    int tty_input;
    struct jobs_s *next;
} jobs_t;

void show_list(jobs_t **job);
void update_status(jobs_t *j, int pid);
int del(jobs_t **head, int pid);
void rev_list(jobs_t **head);
jobs_t *jobs_init(int pgid, char *name, int idp, int tty_input);
void jobs_visual(jobs_t *tmp);
void jobs_visual_tty(jobs_t *tmp);
void jobs_visual_l(jobs_t *tmp);
void jobs_visual_l_tty(jobs_t *tmp);

#endif /* JOB_CONTROL_H_ */
