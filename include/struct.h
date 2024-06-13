/*
** EPITECH PROJECT, 2024
** A-Maze-d
** File description:
** Header for the struct used during the project
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "job_control.h"

typedef struct rc_file_s rc_file_t;

typedef struct dict_s {
    char *key;
    char *value;
    struct dict_s *next;
} dict_t;

typedef struct node_s {
    char *str;
    char operator_code;
    char **env;
    struct node_s *right;
    struct node_s *left;
} node_t;

typedef struct repo_s {
    rc_file_t *file;
    char ***env;
    char *pwd;
    int last_return;
    struct termios orig_termios;
    dict_t *local_vars;
    dict_t *alias;
    jobs_t *jobs;
    char *copy;
    int last_history_pos;
} repo_t;

#endif /* !STRUCT_H_ */
