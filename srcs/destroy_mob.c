/*
** Epitech PROJECT, 2018
** rpg
** File description:
** free mob
*/

#include "rpg.h"

void set_mob_attributes(character_t *mob)
{
	mob->life = 3;
	mob->godmod = 0;
	mob->dir = 0;
	mob->speed = 3;
}

void destroy_mob(character_t *mob)
{
	sfSprite_destroy(mob->moves);
	sfClock_destroy(mob->clock);
}

void free_all_mob(linked_list_t *mobs)
{
	linked_list_t *list = mobs;
	character_t *mob = NULL;

	if (mobs == NULL)
		return;
	for (; list != NULL; list = list->next) {
		mob = list->data;
		destroy_mob(mob);
	}
	my_list_delete(&mobs, NULL);
}
