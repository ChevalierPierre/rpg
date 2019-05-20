/*
** EPITECH PROJECT, 2018
** linked_lib
** File description:
** return number of element in list
*/

#include "linked_lib.h"

int my_list_size(linked_list_t *list)
{
	linked_list_t *tmp = list;
	int i = 0;

	for (; tmp; tmp = tmp->next)
		i++;
	return (i);
}
