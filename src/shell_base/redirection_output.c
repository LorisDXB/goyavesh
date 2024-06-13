/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-alexis.seymour
** File description:
** redirection_output.c
*/

#include "goyave.h"

static int execute_instruction(repo_t *repo, char **tab)
{
    int fd;
    int pid = fork();

    if (pid == 0) {
        if (my_strcmp(del_space(tab[2]), ">") == 0)
            fd = open(del_space(tab[3]), O_CREAT | O_APPEND | O_RDWR, 0644);
        else
            fd = open(del_space(tab[2]), O_CREAT | O_TRUNC | O_RDWR, 0644);
        dup2(fd, STDOUT_FILENO);
        close(fd);
        execute_logical_or(repo, tab[0]);
        exit(0);
    }
    return pid;
}

int execute_redirection_output(repo_t *repo, char **tab)
{
    pid_t pid;

    pid = execute_instruction(repo, tab);
    waitpid(pid, NULL, 0);
    return 0;
}
