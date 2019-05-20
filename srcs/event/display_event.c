/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** display event
*/

#include "rpg.h"

static void display_explode(event_t *event, rpg_t *rpg)
{
	sfIntRect rect = create_rect(177, 182, 0, 0);

	if (sfTime_asMilliseconds
	(sfClock_getElapsedTime(event->clock)) > 20) {
		sfClock_restart(event->clock);
		rect.left = rect.width * event->anim[0];
		event->anim[0]++;
		sfSprite_setTextureRect(event->sprite, rect);
	}
	sfRenderWindow_drawSprite(rpg->window.window, event->sprite, NULL);
}

void display_event(rpg_t *rpg)
{
	linked_list_t *list = rpg->events;
	event_t *event = NULL;

	for (; list != NULL; list = list->next) {
		event = list->data;
		if (event->type == EXPLODE)
			display_explode(event, rpg);
		if (event->anim[0] == event->anim[1]) {
			destroy_event(event);
			my_list_delete(&rpg->events, list);
		}
	}
}
