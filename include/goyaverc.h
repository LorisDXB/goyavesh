/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** radar.h
*/


#ifndef GOYAVERC
    #define GOYAVERC
    #define MAXLINE_RC 1000
    #define GOYAVE_PATH ".goyaverc"

typedef struct repo_s repo_t;

typedef struct rc_file_s {
    char **line_file;
    char **alias;
} rc_file_t;


char *format(repo_t *repo, char *buffer);
int execute_command_next(char **command, char ***env, char **path);
char *some_backtick(repo_t *repo, char *command);
char *format_with_rc(char *str, rc_file_t *file, repo_t *repo);
rc_file_t *init_rc_file(void);
char *str_cat_command(char **str_a);
void clear_end_of_line(char **buffer, int *cursor_pos, repo_t *repo);
void past_line(char **buffer, int *cursor_pos, repo_t *repo);

#endif
