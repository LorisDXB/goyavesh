/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** main.c
*/
#include "goyave.h"

static repo_t *init_repo(void)
{
    repo_t *repo = malloc(sizeof(repo_t));
    char *buf = malloc(sizeof(char) * 512);

    if (!repo || !buf)
        exit(84);
    repo->pwd = strdup(getcwd(buf, 512));
    repo->file = init_rc_file();
    repo->jobs = jobs_init(-20, NULL, 0, -1);
    repo->last_return = 0;
    repo->local_vars = NULL;
    repo->alias = NULL;
    repo->copy = NULL;
    repo->last_history_pos = -1;
    free(buf);
    return repo;
}

static void free_struct(repo_t *repo)
{
    if (repo) {
        if (repo->file) {
            free_array(repo->file->alias);
            free_array(repo->file->line_file);
            free(repo->file);
        }
        if (repo->local_vars)
            free_dict(repo->local_vars);
        if (repo->alias)
            free_dict(repo->alias);
        if (repo->copy)
            free(repo->copy);
        free(repo);
    }
}

int main(int argc, char **argv, char **env)
{
    int nb = isatty(0);
    repo_t *repo = init_repo();
    int ret = 0;

    repo->env = &env;
    if (!argv)
        return 84;
    if (argc != 1) {
        my_printf("USAGE: ./mysh\n");
        return 84;
    }
    if (nb == 0)
        ret = single_line(repo);
    else
        ret = inf_boucle(repo);
    free_struct(repo);
    return ret;
}
