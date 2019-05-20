/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** switch room
*/

#include <stdlib.h>
#include "rpg.h"
#include "my.h"

static sfVector2f ajust_pos(entity_t *ent, room_t *room)
{
	sfVector2f f_pos;

	if (ent->coord.y == 0)
		f_pos = (sfVector2f){ent->pos.x - SCALING * 2,
				ent->pos.y + SCALING};
	else if (ent->coord.x == 0)
		f_pos = (sfVector2f){ent->pos.x, ent->pos.y - SCALING * 2};
	if ((int)(ent->coord.y - 1) == (int)(room->size.y / SCALING))
		f_pos = (sfVector2f){ent->pos.x - (SCALING + SCALING / 2),
				ent->pos.y - SCALING * 2};
	else if ((int)(ent->coord.x - 1) == (int)(room->size.x / SCALING))
		f_pos = (sfVector2f){ent->pos.x - SCALING * 2,
				ent->pos.y - SCALING};
	return (f_pos);
}

static sfVector2f get_entry_pos(char *old_room, room_t *new_room)
{
	linked_list_t *list = new_room->crosspoint;
	int i = 1;
	room_t *room = NULL;
	entity_t *ent = NULL;
	sfVector2f pos;

	for (; list != NULL; list = list->next, i++) {
		room = list->data;
		if (my_strcmp(room->name, old_room) == 0)
			break;
	}
	for (list = new_room->exit; list != NULL; list = list->next) {
		ent = list->data;
		if (i + '0' == ent->type)
			break;
	}
	pos = ajust_pos(ent, new_room);
	return (pos);
}

static room_t *exit_room(room_t *room, entity_t *ent, rpg_t *rpg,
			linked_list_t **mob)
{
	sfVector2f pos;
	char *name = room->name;

	if (sfKeyboard_isKeyPressed(sfKeyE)) {
		room = get_room_by_nbr(room, ent->type - '0');
		pos = get_entry_pos(name, room);
		sfSprite_setPosition(rpg->player->moves, pos);
		rpg->player->pos = pos;
		set_new_mob_pos(*mob, pos);
		load_room_mob(room, mob, rpg);
		wait(200);
	}
	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[0], NULL);
	return (room);
}

room_t *switch_room(room_t *room, rpg_t *rpg, linked_list_t **mobs)
{
	linked_list_t *list = room->exit;
	entity_t *ent = NULL;
	sfVector2f obj_a[2] = {{rpg->player->pos.x +
				rpg->player->collider.width, rpg->player->pos.y
				+ rpg->player->collider.height},
			{rpg->player->pos.x + rpg->player->collider.left,
			rpg->player->pos.y + rpg->player->collider.top}};
	sfVector2f obj_b[2];

	if (my_strcmp(room->name, "boss") == 0)
		return (room);
	for (; list != NULL; list = list->next) {
		ent = list->data;
		obj_b[1] = (sfVector2f){ent->pos.x + SCALING,
					ent->pos.y + SCALING};
		obj_b[0] = ent->pos;
		if (test_collision(obj_a, obj_b))
			room = exit_room(room, ent, rpg, mobs);
	}
	return (room);
}
