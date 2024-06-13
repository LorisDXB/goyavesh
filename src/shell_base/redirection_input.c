/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-alexis.seymour
** File description:
** redirection_input.c
*/

#include "goyave.h"

int execute_pipe_second_bis(int pipefd[2], repo_t *repo, char **tab)
{
    int pid = fork();

    if (pid == 0) {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execute_logical_or(repo, tab[0]);
        exit(0);
    }
    return pid;
}

static int execute_read_from_file(int pipefd[2], char **tab)
{
    int fd;
    int pid = fork();
    int bytes_read = 0;
    char *buffer = malloc(sizeof(char) * 32000);

    if (pid == 0) {
        fd = open(del_space(tab[2]), O_RDONLY);
        if (fd == -1)
            exit(1);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        bytes_read = read(fd, buffer, 32000);
        write(STDOUT_FILENO, buffer, bytes_read);
        exit(0);
    }
    free(buffer);
    return pid;
}

int execute_redirection_input(repo_t *repo, char **tab)
{
    int pipefd[2];
    pid_t pid;
    pid_t pid2;

    pipe(pipefd);
    pid = execute_read_from_file(pipefd, tab);
    pid2 = execute_pipe_second_bis(pipefd, repo, tab);
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
