/*
** EPITECH PROJECT, 2024
** rev_list
** File description:
** rev list for 42sh
*/

#include "goyave.h"

void rev_list(jobs_t **head)
{
    jobs_t *prev = NULL;
    jobs_t *current = *head;
    jobs_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
