/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** history.h
*/

#ifndef HISTORY
    #define HISTORY

    #include "struct.h"

void write_history(char *cmd, char *first_pwd, repo_t *repo);
void print_history(char *pwd);
void history_ind_arrow_up(repo_t *repo, char **tab);
void history_ind_arrow_down(repo_t *repo, char **tab);
char **history_to_array(repo_t *repo);
char *get_history_path(char *first_pwd);
int get_cmd_start(char *str);
char **compare_both_history(char **str, int b, repo_t *repo, int print_error);

#endif
