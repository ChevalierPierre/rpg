/*
** EPITECH PROJECT, 2018
** linked_lib
** File description:
** add element
*/

#include "linked_lib.h"

int my_list_add(linked_list_t **list, void *data)
{
	linked_list_t *elem = malloc(sizeof(linked_list_t));

	if (elem == NULL)
		return (0);
	elem->data = data;
	if (*list == NULL)
		elem->next = NULL;
	else
		elem->next = *list;
	*list = elem;
	return (1);
}
