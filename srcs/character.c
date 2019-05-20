/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** character action function
*/

#include "rpg.h"

static void change_pos_value(character_t *self, int coef)
{
	switch (self->dir) {
	case 0 :
		self->pos.x -= self->speed * coef;
		break;
	case 1 :
		self->pos.x += self->speed * coef;
		break;
	case 2 :
		self->pos.y -= self->speed * coef;
		break;
	case 3 :
		self->pos.y += self->speed * coef;
		break;
	}
}

static void move_sprite(room_t *room, character_t *self, linked_list_t *mobs)
{
	change_pos_value(self, 1);
	if (check_collision(room, self, mobs))
		change_pos_value(self, -1);
	sfSprite_setPosition(self->moves, self->pos);
	if (self->type == PLAYER)
		sfSprite_setPosition(self->attack, self->pos);
}

void display_static_character(sfRenderWindow *window, character_t *self)
{
	self->anim_move[0] = 0;
	self->rect_m.left = self->rect_m.width * self->dir;
	self->rect_m.top = self->rect_m.height * 4;
	sfSprite_setTextureRect(self->moves, self->rect_m);
	sfRenderWindow_drawSprite(window, self->moves, NULL);
}

void move_character(anim_t anim, int dir, room_t *room, linked_list_t *mobs)
{
	if (anim.self->anim_move[0] == anim.self->anim_move[1] || anim.self->dir
	!= dir) {
		anim.self->dir = dir;
		anim.self->anim_move[0] = 0;
	}
	move_sprite(room, anim.self, mobs);
	if (anim.self->type == PLAYER && anim.self->godmod % 2 != 0)
		return;
	if (sfTime_asMilliseconds
	(sfClock_getElapsedTime(anim.self->clock)) > 50) {
		sfClock_restart(anim.self->clock);
		anim.self->rect_m.left = anim.self->rect_m.width
			* anim.self->anim_move[0];
		anim.self->rect_m.top = anim.self->rect_m.height
			* anim.self->dir;
		sfSprite_setTextureRect(anim.self->moves,
					anim.self->rect_m);
		anim.self->anim_move[0]++;
	}
	sfRenderWindow_drawSprite(anim.window, anim.self->moves, NULL);
}

void character_attack(sfRenderWindow *window, character_t *self)
{
	if (self->anim_atck[0] == self->anim_atck[1])
		self->anim_atck[0] = 0;
	if (sfTime_asMilliseconds(sfClock_getElapsedTime(self->clock)) > 50) {
		sfClock_restart(self->clock);
		self->rect_a.left = self->rect_a.width * self->anim_atck[0];
		self->rect_a.top = self->rect_a.height * self->dir;
		sfSprite_setTextureRect(self->attack, self->rect_a);
		self->anim_atck[0]++;
	}
	sfRenderWindow_drawSprite(window, self->attack, NULL);
}
