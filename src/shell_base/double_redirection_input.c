/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-alexis.seymour
** File description:
** double_redirection_input.c
*/

#include "goyave.h"

static int get_text_next(int pipefd[2], char *buffer,
    int total_bytes)
{
    int pid = fork();

    if (pid == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        write(STDOUT_FILENO, buffer, total_bytes);
        exit(0);
    }
    return pid;
}

static int get_text(int pipefd[2], char **tab)
{
    char *buffer = "\0";
    char *new_buffer = "\0";
    char *verif_buffer = "\0";
    size_t len = 0;
    int total_bytes = 0;

    while (my_strcmp(del_space(tab[3]), del_space(verif_buffer)) != 0) {
        write(STDOUT_FILENO, "? ", 2);
        buffer = my_strcat(buffer, new_buffer);
        new_buffer = NULL;
        len = getline(&new_buffer, &len, stdin);
        verif_buffer = my_strdup(new_buffer);
        total_bytes += len;
        verif_buffer[len - 1] = '\0';
    }
    return get_text_next(pipefd, buffer, total_bytes);
}

int execute_double_redirection_input(repo_t *repo, char **tab)
{
    int pipefd[2];
    pid_t pid;
    pid_t pid2;

    pipe(pipefd);
    pid = get_text(pipefd, tab);
    pid2 = execute_pipe_second_bis(pipefd, repo, tab);
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
