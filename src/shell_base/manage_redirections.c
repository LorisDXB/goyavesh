/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-alexis.seymour
** File description:
** manage_redirections.c
*/

#include "goyave.h"


int verif_redirections(char **tab)
{
    if (my_strcmp(tab[0], "|") == 0) {
        write(2, "Invalid null command.\n", 22);
        return 1;
    }
    return 0;
}

int manage_redirections(repo_t *repo, char *buffer)
{
    char **tab = my_str_to_word_array_keep(buffer, "><|");

    if (verif_redirections(tab) == 1) {
        free_array(tab);
        return 1;
    }
    if (my_arrlen(tab) == 1) {
        free_array(tab);
        return check_command(repo, buffer);
    } else if (tab[1][0] == '|' && tab[2] != NULL && tab[2][0] != '|')
        execute_pipe(repo, tab);
    if (tab[1][0] == '>')
        execute_redirection_output(repo, tab);
    if (tab[1][0] == '<' && tab[2] != NULL && tab[2][0] == '<')
        execute_double_redirection_input(repo, tab);
    else if (tab[1][0] == '<' && tab[2][0] != '<')
        execute_redirection_input(repo, tab);
    free_array(tab);
    return 0;
}
