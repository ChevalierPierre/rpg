/*
** EPITECH PROJECT, 2018
** linked_lib
** File description:
** list delete
*/

#include "linked_lib.h"

void delete_all_list(linked_list_t *list)
{
	linked_list_t *tmp = list;
	linked_list_t *prev_tmp = NULL;

	for (; tmp; prev_tmp = tmp, tmp = tmp->next, free(prev_tmp));
}

void my_list_delete(linked_list_t **list, linked_list_t *elem)
{
	linked_list_t *tmp = *list;
	linked_list_t *prev_tmp = NULL;
	int i = 0;

	if (elem == NULL)
		return (delete_all_list(tmp));
	for (i = 0; tmp; prev_tmp = tmp, tmp = tmp->next, i++)
		if (tmp == elem)
			break;
	if (tmp == NULL)
		return;
	if (i == 0)
		*list = (*list)->next;
	else
		prev_tmp->next = tmp->next;
	free(elem);
}
