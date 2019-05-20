/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** collisions functions
*/

#include "rpg.h"

int test_collision(sfVector2f *obj_a, sfVector2f *obj_b)
{
	if (((obj_a[0].y < obj_b[0].y && obj_b[0].y < obj_a[1].y) ||
	(obj_a[0].y < obj_b[1].y && obj_b[1].y < obj_a[1].y)) &&
	((obj_a[0].x < obj_b[0].x && obj_b[0].x < obj_a[1].x) ||
	(obj_a[0].x < obj_b[1].x && obj_b[1].x < obj_a[1].x)))
		return (1);
	return (0);
}

static int test_entity_collision(linked_list_t *entity, sfVector2f *obj_a)
{
	linked_list_t *list = entity;
	entity_t *ent;
	sfVector2f obj_b[2];

	for (; list != NULL; list = list->next) {
		ent = list->data;
		if (ent->type != 'X' && ent->type != 'W' && ent->type != '?')
			continue;
		obj_b[1] = (sfVector2f){ent->pos.x + SCALING,
					ent->pos.y + SCALING};
		obj_b[0] = ent->pos;
		if (test_collision(obj_a, obj_b))
			return (1);
	}
	return (0);
}

static int test_edge_collision(sfVector2f *obj_a, sfVector2f *obj_b)
{
	if (((obj_a[0].y < obj_b[0].y && obj_b[0].y < obj_a[1].y) ||
	(obj_a[0].y < obj_b[1].y && obj_b[1].y < obj_a[1].y)) ||
	((obj_a[0].x < obj_b[0].x && obj_b[0].x < obj_a[1].x) ||
	(obj_a[0].x < obj_b[1].x && obj_b[1].x < obj_a[1].x)))
		return (1);
	return (0);
}

int test_mob_collision(character_t *self, sfVector2f *obj_a,
		linked_list_t *mobs)
{
	linked_list_t *list = mobs;
	character_t *mob = NULL;
	sfVector2f *obj_b;

	for (; list != NULL; list = list->next) {
		mob = list->data;
		if (mob == self)
			continue;
		obj_b = get_character_hitbox(mob);
		if (test_collision(obj_a, obj_b)) {
			free(obj_b);
			return (1);
		}
		free(obj_b);
	}
	return (0);
}

int check_collision(room_t *room, character_t *self, linked_list_t *mobs)
{
	sfVector2f obj_a[2] = {{self->pos.x + self->collider.width,
				self->pos.y + self->collider.height},
			{self->pos.x + self->collider.left,
			self->pos.y + self->collider.top}};
	sfVector2f or = sfSprite_getPosition(room->gnd);
	sfVector2f up[2] = {or, {WIN_SIZE.x, 0}};
	sfVector2f down[2] = {{0, WIN_SIZE.y}, or};
	sfVector2f left[2] = {{or.x + room->size.x + SCALING, or.y}, WIN_SIZE};
	sfVector2f right[2] = {{or.x, or.y + room->size.y + SCALING}, WIN_SIZE};

	if (test_edge_collision(obj_a, up) ||
	test_edge_collision(obj_a, down) ||
	test_edge_collision(obj_a, left) || test_edge_collision(obj_a, right))
		return (1);
	if (test_entity_collision(room->entity, obj_a))
		return (1);
	if (self->type != PLAYER && test_mob_collision(self, obj_a, mobs))
		return (1);
	return (0);
}
