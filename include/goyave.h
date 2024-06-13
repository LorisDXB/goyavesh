/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** radar.h
*/


#ifndef GOYAVE
    #define GOYAVE

    #define GREEN(string) "\x1b[32m" string "\x1b[0m"
    #define RED(string) "\x1b[31m" string "\x1b[0m"
    #define YELLOW(string) "\x1b[33m" string "\x1b[0m"
    #define BLUE(string) "\x1b[34m" string "\x1b[0m"
    #define MAGENTA(string) "\x1b[35m" string "\x1b[0m"
    #define CYAN(string) "\x1b[36m" string "\x1b[0m"

    #include "standard.h"
    #include "struct.h"
    #include "goyaverc.h"
    #include "my.h"
    #include "ast.h"
    #include "local_vars.h"
    #include "alias_command.h"
    #include "history.h"
    #include "job_control.h"



int exec_bg(repo_t *repo, char **params);
void init_termios(repo_t *repo);
void set_termios_echo_mod(repo_t *repo);
void set_termios_canon_mod(repo_t *repo);
void go_all_left(char **buffer, int *cursor_pos, repo_t *repo);
void update(char **buffer, repo_t *repo, int *cursor_pos);
char *get_all_prog(char *path, char *buff);
void init_termios(repo_t *repo);
int set_env(char ***env, char **params);
int change_directory(char ***env, char **params);
char *get_file_to_path(char **command, char **path);
int execute_double_redirection_input(repo_t *repo, char **tab);
int execute_pipe(repo_t *repo, char **tab);
int inf_boucle(repo_t *repo);
int manage_redirections(repo_t *repo, char *buffer);
int execute_redirection_input(repo_t *repo, char **tab);
int execute_redirection_output(repo_t *repo, char **tab);
int single_line(repo_t *repo);
int unset_env_hub(char ***env, char **params);
int execute_pipe_second_bis(int pipefd[2], repo_t *repo, char **tab);
int check_command(repo_t *repo, char *buffer);
int print_env(char **env);
int verif_command(repo_t *repo, char *buffer);
int find_index_env(char **env, char *params);
char **check_path(char ***env);
int execute_command(repo_t *repo, char ***env, char *buffer);
void print_char(char **buffer, int *cursor_pos, repo_t *repo, char c);
void clear_line(void);
void move_cursor_left(int n, char *buffer);
void backspace(char **buffer, int *cursor_pos, repo_t *repo);
void delete(char **buffer, int *cursor_pos, repo_t *repo);
void arrow(char **buffer, int *cursor_pos, repo_t *repo);
jobs_t *execadv(repo_t *repo, int id, char *name, int tty_input);
int ping_jobs(repo_t *repo);
int check_which(repo_t *repo, char **params);
int check_where(repo_t *repo, char **params);
int execute_logical_and(repo_t *repo, char *buf);
int execute_logical_or(repo_t *repo, char *buf);
int send_to_child(int pipefd[2], repo_t *repo);
int listen_4_signals(int pipefd[2], repo_t *repo);
int sig_reroute(jobs_t **arr, repo_t *repo);
void goyave_art(void);
int exec_ext(repo_t *repo, int pid, char *name, int bg);
int exec_fg(repo_t *repo, char **params);
int jobs(repo_t *repo, char **params);

#endif
