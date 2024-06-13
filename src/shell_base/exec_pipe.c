/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-alexis.seymour
** File description:
** exec_pipe.c
*/

#include "goyave.h"

static int check_if_command(char *str)
{
    char **params = my_str_to_word_array(str, " \t\0");

    if (my_strcmp(params[0], "cd") == 0)
        return 1;
    if (my_strcmp(params[0], "setenv") == 0)
        return 1;
    if (my_strcmp(params[0], "unsetenv") == 0)
        return 1;
    return 0;
}

static char *recreate_buffer(char **tab)
{
    int i = 0;
    char *str = "\0";

    while (tab[i] != NULL) {
        str = my_strcat(str, tab[i]);
        i++;
    }
    return str;
}

static int execute_pipe_first(int pipefd[2], repo_t *repo, char **tab)
{
    int pid = fork();

    if (pid == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        close(pipefd[0]);
        execute_logical_or(repo, tab[0]);
        exit(0);
    }
    return pid;
}

static int execute_pipe_second(int pipefd[2], repo_t *repo, char **tab)
{
    int pid;

    if (check_if_command(tab[2])) {
        check_command(repo, tab[2]);
        return -1;
    }
    pid = fork();
    if (pid == 0) {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execute_logical_or(repo, recreate_buffer(tab + 2));
        exit(0);
    }
    return pid;
}

int execute_pipe(repo_t *repo, char **tab)
{
    int pipefd[2];
    pid_t pid;
    pid_t pid2;

    pipe(pipefd);
    pid = execute_pipe_first(pipefd, repo, tab);
    pid2 = execute_pipe_second(pipefd, repo, tab);
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid, NULL, 0);
    if (pid2 != -1)
        waitpid(pid2, NULL, 0);
    return 0;
}
