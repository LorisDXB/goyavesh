/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** getline_loop.c
*/
#include "goyave.h"

static void next_switch(char **buffer, int *cursor_pos, repo_t *repo, char c)
{
    switch (c) {
        case 11:
            clear_end_of_line(buffer, cursor_pos, repo);
            break;
        case 1:
            go_all_left(buffer, cursor_pos, repo);
            break;
        case 25:
            past_line(buffer, cursor_pos, repo);
            break;
        case 126:
            delete(buffer, cursor_pos, repo);
            break;
        default:
            print_char(buffer, cursor_pos, repo, c);
            break;
    }
}

static void go_to_switch(char **buffer, int *cursor_pos, repo_t *repo, char c)
{
    switch (c) {
        case '\x7f':
            backspace(buffer, cursor_pos, repo);
            break;
        case '\x1b':
            arrow(buffer, cursor_pos, repo);
            break;
        case '\t':
            if (strlen(*buffer) == 0)
                return;
            *buffer = get_all_prog(getcwd(NULL, 0), *buffer);
            *cursor_pos = strlen(*buffer);
            update(buffer, repo, cursor_pos);
            break;
        default:
            next_switch(buffer, cursor_pos, repo, c);
            break;
        }
}

static void getline_loop_next(char **buffer, int *cursor_pos, repo_t *repo,
    int *exit_i)
{
    char c;
    ssize_t nread = read(STDIN_FILENO, &c, 1);

    if (nread == -1) {
        perror("read");
        exit(1);
    } else if (nread == 0) {
        return;
    }
    if (c == '\n') {
        *exit_i = 1;
        return;
    } else if (c == 4)
        *exit_i = 4;
    go_to_switch(buffer, cursor_pos, repo, c);
    fflush(stdout);
}

void signalhandler(int pid)
{
    if (pid == 0)
        return;
    return;
}

static int getline_loop(repo_t *repo, char **buffer)
{
    int exit_i = 0;
    int cursor_pos = 0;
    char *cwd_get = getcwd(NULL, 512);

    (*buffer)[0] = '\0';
    printf("\033[s");
    if (repo->last_return == 0)
        my_printf("╭─%s\n╰─" GREEN("➤") " ", cwd_get);
    else
        my_printf("╭─%s\n╰─" RED("➤") " ", cwd_get);
    while (exit_i == 0) {
        getline_loop_next(buffer, &cursor_pos, repo, &exit_i);
    }
    repo->last_history_pos = -1;
    free(cwd_get);
    printf("\n");
    write_history((*buffer), repo->pwd, repo);
    if (exit_i == 4)
        return -1;
    return verif_command(repo, (*buffer));
}

static void init_signal_termios(repo_t *repo)
{
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    act.sa_handler = &signalhandler;
    act.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &act, NULL);
    init_termios(repo);
}

int inf_boucle(repo_t *repo)
{
    char *pwd = calloc(sizeof(char), 512);
    char *buffer = calloc(sizeof(char), 1024);
    int car = 0;

    init_signal_termios(repo);
    while (car != -1 && my_strcmp(buffer, "exit") != 0) {
        car = getline_loop(repo, &buffer);
    }
    free(pwd);
    free(buffer);
    free(repo->pwd);
    return 0;
}
