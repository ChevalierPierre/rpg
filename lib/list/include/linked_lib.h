/*
** EPITECH PROJECT, 2018
** linked_lib
** File description:
** linked list structure
*/

#include <stdlib.h>

typedef struct linked_list_s {
	void *data;
	struct linked_list_s *next;
}linked_list_t;
