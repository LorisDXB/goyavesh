/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-alexis.seymour
** File description:
** get_length_list.c
*/

#include "../include/my.h"

int get_length_list(linked_list_t **list)
{
    linked_list_t *tmp = *(linked_list_t **)list;
    int i = 0;

    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    return i;
}
