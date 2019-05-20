/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** creating event
*/

#include "rpg.h"

void destroy_event(event_t *event)
{
	sfSprite_destroy(event->sprite);
	sfClock_destroy(event->clock);
	free(event);
}

event_t *create_event(sfTexture **texture_bank, sfVector2f pos, int type)
{
	event_t *event = malloc(sizeof(event_t));
	sfSprite *sprite = sfSprite_create();

	if (event == NULL || sprite == NULL)
		return (NULL);
	if (type == EXPLODE) {
		event->anim[0] = 0;
		event->anim[1] = 9;
		sfSprite_setTexture(sprite, texture_bank[33], sfTrue);
	}
	event->type = type;
	event->clock = sfClock_create();
	sfSprite_setPosition(sprite, pos);
	if (event->clock == NULL || sprite == NULL)
		return (NULL);
	event->sprite = sprite;
	return (event);
}

void mob_death(rpg_t *rpg, character_t *mob)
{
	event_t *event = create_event(rpg->texture_bank, mob->pos, EXPLODE);

	if (event == NULL)
		return;
	if (!my_list_add(&rpg->events, event))
		rpg->events = NULL;
}
