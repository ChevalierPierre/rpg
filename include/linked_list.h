/*
** EPITECH PROJECT, 2018
** linked_lib
** File description:
** linked list structure
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct linked_list_s {
	void *data;
	struct linked_list_s *next;
}linked_list_t;

int my_list_add(linked_list_t **, void *);
int my_list_size(linked_list_t *);
void my_list_delete(linked_list_t **, linked_list_t *);

#endif
