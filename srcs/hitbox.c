/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** hitnbox recuperation
*/

#include "rpg.h"

static sfVector2f *left_right_hitbox(character_t *self)
{
	sfVector2f *hb = malloc(sizeof(sfVector2f) * 2);

	if (self->dir == 0) {
		hb[0] = (sfVector2f){self->pos.x + self->collider.width + 20,
				self->pos.y + self->collider.height};
		hb[1] = (sfVector2f){self->pos.x + self->collider.width -
				HIT_RANGE + 20, self->pos.y +
				self->collider.height + self->collider.top};
	} if (self->dir == 1) {
		hb[0] = (sfVector2f){self->pos.x + self->collider.width +
				self->collider.left - 20, self->pos.y +
				self->collider.height};
		hb[1] = (sfVector2f){self->pos.x + self->collider.left
				+ HIT_RANGE, self->pos.y +
				self->collider.top + 10};
	}
	return (hb);
}

static sfVector2f *up_down_hitbox(character_t *self)
{
	sfVector2f *hb = malloc(sizeof(sfVector2f) * 2);

	if (self->dir == 2) {
		hb[0] = (sfVector2f){self->pos.x + self->collider.width,
				self->pos.y + self->collider.height + 20};
		hb[1] = (sfVector2f){self->pos.x + self->collider.left + 20,
				self->pos.y + self->collider.height
				- HIT_RANGE + 20};
	} if (self->dir == 3) {
		hb[0] = (sfVector2f){self->pos.x + self->collider.width,
					self->pos.y + self->collider.height
					+ self->collider.top - 20};
		hb[1] = (sfVector2f){self->pos.x + self->collider.left
				+ self->collider.width, self->pos.y
				+ self->collider.top + HIT_RANGE};
	}
	return (hb);
}

sfVector2f *get_attack_hitbox(character_t *self)
{
	sfVector2f *hb;

	if (self->dir == 0 || self->dir == 1)
		hb = left_right_hitbox(self);
	else
		hb = up_down_hitbox(self);
	return (hb);
}

sfVector2f *get_character_hitbox(character_t *self)
{
	sfVector2f *obj_a = malloc(sizeof(sfVector2f) * 2);

	obj_a[0] = (sfVector2f){self->pos.x + self->collider.width,
		self->pos.y + self->collider.height};
	obj_a[1] = (sfVector2f){self->pos.x + self->collider.width
				+ self->collider.left,
		self->pos.y + self->collider.height + self->collider.top};
	return (obj_a);
}
