/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** local_vars.h
*/

#ifndef LOCAL_VARS_H_
    #define LOCAL_VARS_H_

    #include "struct.h"

dict_t *add_local_var(dict_t *local_vars, char **params, int *i);
dict_t *add_local_var_comp(dict_t *local_vars, char **params, int *i);
int all_vars_exist(char **env, dict_t *local_vars, char *buffer);
char *array_to_str_spaces(char **tab);
int complete_dec(char *str);
int correct_set(char **command);
int export_env_var(repo_t *repo, char **params);
char *find_var_name(char *buffer, int *i);
void free_dict(dict_t *local_vars);
char *get_var_name(char *string);
char *get_var_value(char *string);
int is_assign(char **params);
int is_var_used(char *buffer);
int len_array(char **array);
char **replace_vars(repo_t *repo, char *buffer, char **params);
int set_local_var(repo_t *repo, char **params);
int unset_local_var(repo_t *repo, char **params);
dict_t *update_local_var(dict_t *local_vars, char **params, int *i);
dict_t *update_local_var_comp(dict_t *local_vars, char **params, int *i);

#endif /* LOCAL_VARS_H_ */
