/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** mob position manager
*/

#include "rpg.h"

void set_new_mob_pos(linked_list_t *mobs, sfVector2f pos)
{
	linked_list_t *tmp = mobs;
	character_t *mob;

	for (; tmp != NULL; tmp = tmp->next) {
		mob = tmp->data;
		mob->pos = pos;
	}
}
