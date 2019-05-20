/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** display room
*/

#include "rpg.h"

static sfVector2f ajust_pos(room_t *room, entity_t *ent)
{
	sfVector2f f_pos;

	if (ent->coord.y == 0)
		f_pos = (sfVector2f){ent->pos.x, ent->pos.y - WALL_SIZE / 2};
	else if (ent->coord.x == 0)
		f_pos = (sfVector2f){ent->pos.x - WALL_SIZE / 2, ent->pos.y};
	if ((int)(ent->coord.y - 1) == (int)(room->size.y / SCALING))
		f_pos = (sfVector2f){ent->pos.x , ent->pos.y + WALL_SIZE / 2
				- (WALL_SIZE / 2 - SCALING)};
	else if ((int)(ent->coord.x - 1) == (int)(room->size.x / SCALING))
		f_pos = (sfVector2f){ent->pos.x + WALL_SIZE / 2 -
				(WALL_SIZE / 2 - SCALING), ent->pos.y};
	return (f_pos);

}

static void entity(entity_t *ent, rpg_t *rpg, sfVector2f pos)
{
	if (ent->type == 'W') {
		sfSprite_setPosition(rpg->utils_sprite[7], pos);
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[7], NULL);
	} if (ent->type == '?') {
		sfSprite_setPosition(rpg->utils_sprite[4], pos);
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[4], NULL);
	} if (ent->type == 'K') {
		sfSprite_setPosition(rpg->utils_sprite[6], pos);
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[6], NULL);
	} if (ent->type == 'o') {
		sfSprite_setPosition(rpg->utils_sprite[5], pos);
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[5], NULL);
	}
}

static void display_entity(room_t *room, rpg_t *rpg)
{
	linked_list_t *list = room->entity;
	entity_t *ent;
	sfVector2f pos;

	for (; list != NULL; list = list->next) {
		ent = list->data;
		pos = (sfVector2f){ent->pos.x + 5, ent->pos.y - SCALING};
		entity(ent, rpg, pos);
	}
}

static void display_doors(sfRenderWindow *window, room_t *room)
{
	entity_t *ent;
	linked_list_t *list = room->exit;
	sfVector2f f_pos;

	for (; list != NULL; list = list->next) {
		ent = list->data;
		f_pos = ajust_pos(room, ent);
		sfSprite_setPosition(room->door, f_pos);
		sfRenderWindow_drawSprite(window, room->door, NULL);
	}
}

void disp_room(room_t *room, rpg_t *rpg)
{
	sfRenderWindow_drawSprite(rpg->window.window, room->wall, NULL);
	sfRenderWindow_drawSprite(rpg->window.window, room->gnd, NULL);
	display_entity(room, rpg);
	display_doors(rpg->window.window, room);
}
