/*
** EPITECH PROJECT, 2024
** GoyaveSh_mirror
** File description:
** init_termios
*/

#include "goyave.h"

void init_termios(repo_t *repo)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &(repo->orig_termios));
    raw = repo->orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void set_termios_echo_mod(repo_t *repo)
{
    struct termios raw;

    raw = repo->orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void set_termios_canon_mod(repo_t *repo)
{
    struct termios canon_termios;

    canon_termios = repo->orig_termios;
    canon_termios.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &canon_termios);
}
