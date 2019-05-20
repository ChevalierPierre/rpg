/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** room utility functions
*/

#include <stdlib.h>
#include "rpg.h"
#include "my.h"

room_t *get_room_by_name(char *name, linked_list_t *rooms)
{
	linked_list_t *list = rooms;
	room_t *room = NULL;

	for (; list != NULL; list = list->next) {
		room = list->data;
		if (my_strcmp(name, room->name) == 0)
			return (room);
	}
	return (NULL);
}

room_t *get_room_by_nbr(room_t *room, int nbr)
{
	linked_list_t *list = room->crosspoint;
	room_t *new_room = NULL;

	for (int i = 1; i != nbr; i++)
		list = list->next;
	new_room = list->data;
	return (new_room);
}
