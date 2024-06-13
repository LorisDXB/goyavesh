/*
** EPITECH PROJECT, 2023
** GoyaveSh_mirror
** File description:
** ast.h
*/

#ifndef AST
    #define AST

    #include "struct.h"

void pipe_recc(char *cmd, repo_t *repo, int *to_ret);
void reccursive(node_t **node, int start, int end, char *str);
int node_is_operator(node_t *root);
int search_red(char *str, int start, int end);
int search_sep(char *str, int start, int end);
int search_pipe(char *str, int start, int end);
void tree_handling(repo_t *repo, char *cmd, int *to_ret);
char *remove_first_space_from_str(char *str);
char *remove_last_space_from_str(char *str);
void free_ast(node_t *node);
int is_built_in(char *str);
char *my_strdup_start_end(char *src, int start, int end);
char **split_pipe(char *str);
void op_func(node_t *root, int *to_ret, repo_t *repo);
int find_pwd_from_env(char ***env, char **params);
int find_old_pwd_from_env(char ***env, char **params);
int search_and(char *str, int start, int end);
char *remove_line_break(char *str);
void op_pipe(node_t *root, int *pipe_before, int *to_ret,
    repo_t *repo);
void op_and(node_t *root, int *to_ret, repo_t *repo);
int search_or(char *str, int start, int end);
void op_or(node_t *root, int *to_ret, repo_t *repo);

#endif
