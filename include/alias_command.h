/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** alias_command.h
*/

#ifndef ALIAS_COMMAND_H_
    #define ALIAS_COMMAND_H_

int alias_command(repo_t *repo, char **params);
int already_in(dict_t *dict, char *param);
char *command_walias(char *alias, char **params);
char *is_alias(dict_t *alias, char *command);
dict_t *push_to_list(dict_t *dict, char *key, char *value);
void print_alias(dict_t *alias);
int unalias_command(repo_t *repo, char **params);

#endif /* ALIAS_COMMAND_H_ */
