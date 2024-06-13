/*
** EPITECH PROJECT, 2024
** GoyaveSh_mirror
** File description:
** backtick
*/

#include "goyave.h"

static char *my_array_to_str_with_space(char **tab)
{
    int i = 0;
    char *str = "\0";

    while (tab[i] != NULL) {
        str = my_strcat(str, tab[i]);
        if (tab[i + 1] != NULL)
            str = my_strcat(str, " ");
        i++;
    }
    return str;
}

static char *get_backtick_command(char *str)
{
    int i = 0;
    int b = 0;
    char *send = NULL;

    for (; str[i] != '`' && str[i] != '\0'; i++);
    if (str[i] == '`')
        send = strdup(str + i + 1);
    else
        return NULL;
    for (; send[b] != '`' && send[b] != '\0'; b++);
    if (send[b] == '`')
        send[b] = '\0';
    else {
        return NULL;
    }
    return send;
}

static int fork_vanish(char *bt_command, repo_t *repo, int pipefd[2])
{
    int child_pid = fork();

    if (child_pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        verif_command(repo, bt_command);
        exit(0);
    }
    return child_pid;
}

static char **exec_vanish_command(repo_t *repo, char *bt_command)
{
    char buffer[32000] = {0};
    int status = 0;
    int pipefd[2];
    int pid = 0;

    pipe(pipefd);
    pid = fork_vanish(bt_command, repo, pipefd);
    waitpid(pid, &status, 0);
    close(pipefd[1]);
    while (read(pipefd[0], buffer, 31999) > 0);
    close(pipefd[0]);
    if (my_strlen(buffer) == 0)
        return NULL;
    return my_str_to_word_array(buffer, "\n");
}

static char *end_bk(int i, char *cmd, char *send, int i_b)
{
    for (; cmd[i] != '\0'; i++) {
        send[i_b] = cmd[i];
        i_b++;
    }
    send[i_b - 1] = '\0';
    if (strlen(send) == 0)
        return NULL;
    return send;
}

static char *replace_for_backtick(char *bt_cmd, char *cmd)
{
    char *send = malloc(strlen(cmd) + strlen(bt_cmd));
    int i = 0;
    int i_b = 0;

    for (; cmd[i] != '`' && cmd[i] != '\0'; i++) {
        send[i_b] = cmd[i];
        i_b++;
    }
    i++;
    for (int b = 0; bt_cmd[b] != '\0'; b++) {
        send[i_b] = bt_cmd[b];
        i_b++;
    }
    for (; cmd[i] != '`' && cmd[i] != '\0'; i++);
    if (cmd[i] == '\0')
        return NULL;
    i++;
    return end_bk(i, cmd, send, i_b);
}

char *some_backtick(repo_t *repo, char *command)
{
    char *bt_command = get_backtick_command(command);
    char **array_commande = NULL;
    char *send = NULL;

    if (bt_command == NULL)
        return command;
    array_commande = exec_vanish_command(repo, bt_command);
    if (array_commande == NULL)
        send = replace_for_backtick("\0", command);
    else
        send = replace_for_backtick(my_array_to_str_with_space
        (array_commande), command);
    if (send == NULL) {
        write(2, ": Command not found.\n", 21);
        return NULL;
    }
    return send;
}

char *format(repo_t *repo, char *buffer)
{
    if (strlen(buffer) == 0)
        return NULL;
    buffer = format_with_rc(buffer, repo->file, repo);
    if (buffer != NULL && strlen(buffer) >= 1 &&
        buffer[my_strlen(buffer) - 1] == '\n')
        buffer[my_strlen(buffer) - 1] = '\0';
    return buffer;
}
