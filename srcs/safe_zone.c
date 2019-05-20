/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** safe zone events
*/

#include "rpg.h"

int exit_tavern(room_t *room, rpg_t *rpg)
{
	linked_list_t *list = room->exit;
	entity_t *ent = NULL;
	sfVector2f *obj_a = get_character_hitbox(rpg->player);
	sfVector2f obj_b[2];
	int ret = 0;

	for (; list != NULL; list = list->next, ret = 0) {
		ent = list->data;
		obj_b[1] = (sfVector2f){ent->pos.x + SCALING,
					ent->pos.y + SCALING};
		obj_b[0] = ent->pos;
		if ((ret = test_collision(obj_a, obj_b)) &&
		sfKeyboard_isKeyPressed(sfKeyE))
			break;
		if (ret)
			sfRenderWindow_drawSprite(rpg->window.window,
						rpg->utils_sprite[0], NULL);
	}
	free(obj_a);
	return (ret);
}

static void set_zone(sfVector2f (*obj)[2], entity_t *ent)
{
	(*obj)[0] = ent->pos;
	(*obj)[1] = (sfVector2f){ent->pos.x + SCALING, ent->pos.y
				+ SCALING};
}

int on_shop(room_t *room, rpg_t *rpg)
{
	linked_list_t *list = room->entity;
	entity_t *ent = NULL;
	sfVector2f *obj_a = get_character_hitbox(rpg->player);
	sfVector2f obj_b[2];
	int ret = 0;

	for (; list != NULL; list = list->next, ret = 0) {
		ent = list->data;
		if (ent->type != 'S')
			continue;
		set_zone(&obj_b, ent);
		if ((ret = test_collision(obj_a, obj_b)) &&
		sfKeyboard_isKeyPressed(sfKeyE))
			break;
		if (ret)
			sfRenderWindow_drawSprite(rpg->window.window,
						rpg->utils_sprite[19], NULL);
	}
	free(obj_a);
	return (ret);
}

void process_tavern(rpg_t *rpg, int i)
{
	if (i == 20)
		write_text("config/text/begin.text", rpg);
	test_close(rpg->window.window);
	sfRenderWindow_clear(rpg->window.window, sfBlack);
	disp_room(rpg->tavern, rpg);
}
