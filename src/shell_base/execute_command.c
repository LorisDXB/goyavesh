/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** execute_command.c
*/
#include "goyave.h"



int execute_command_next(char **command, char ***env, char **path)
{
    get_file_to_path(command, path);
    if (my_strncmp(command[0], "/", 0) == 0
        || my_strncmp(command[0], "./", 1) == 0)
        execve(command[0], command, *env);
    if (errno == 8) {
        write(2, command[0], my_strlen(command[0]));
        write(2, ": Exec format error.", 20);
        write(2, " Wrong Architecture.\n", 21);
        exit(1);
    } else if (errno == 13 && access(command[0], X_OK) == 0) {
        write(2, command[0], my_strlen(command[0]));
        write(2, ": Permission denied.\n", 21);
        exit(1);
    }
    write(2, command[0], my_strlen(command[0]));
    write(2, ": Command not found.\n", 21);
    exit(1);
}

static int fork_error(int pid)
{
    if (pid == -1) {
        perror("Fork error");
        return 84;
    }
    return 0;
}

int exec_ext(repo_t *repo, int pid, char *name, int bg)
{
    int status;
    pid_t result = 0;

    ping_jobs(repo);
    result = waitpid(pid, &status, WUNTRACED);
    if (result > 0) {
        if (WIFSTOPPED(status)) {
            execadv(repo, pid, name, bg);
            update_status(repo->jobs, result);
        }
    }
    set_termios_echo_mod(repo);
    return status;
}

static int verif_e_in_buffer(char **buffer)
{
    int len = strlen(*buffer) - 1;

    while (len >= 0) {
        if ((*buffer)[len] == ' ')
            len--;
        if ((*buffer)[len] == '&') {
            *buffer = my_strncpy(*buffer, *buffer, len);
            return 1;
        }
        if ((*buffer)[len] != ' ' && (*buffer)[len] != '&')
            return 0;
    }
    return 0;
}

int execute_command(repo_t *repo, char ***env, char *buffer)
{
    int go_background = verif_e_in_buffer(&buffer);
    int pid = 0;
    char **command = NULL;
    char **path = check_path(env);
    int ret = 0;

    set_termios_canon_mod(repo);
    command = my_str_to_word_array(buffer, " \t\0");
    pid = fork();
    if (fork_error(pid) == 84)
        exit(84);
    if (pid == 0)
        execute_command_next(command, env, path);
    if (go_background == 1) {
        kill(pid, SIGSTOP);
    }
    ret = exec_ext(repo, pid, command[0], go_background);
    free_array(command);
    free_array(path);
    return ret;
}
