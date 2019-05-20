/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu
*/

#include "rpg.h"

void smooth_transparent(sprite_t *sprite, int speed)
{
	if (sprite->color.a != 0) {
		if ((sprite->color.a - speed) < 0)
			sprite->color.a = 0;
		else
			sprite->color.a = sprite->color.a - speed;
		sfSprite_setColor(sprite->sprite, sprite->color);
	}
}

void smooth_get_color(sprite_t *sprite)
{
	if (sprite->color.a < 250) {
		sprite->color.a += 2;
		sfSprite_setColor(sprite->sprite, sprite->color);
	}
}

void smooth_blink(sfSprite *sprite)
{
	static sfColor color = {255, 255, 255, 255};
	static int i = 0;

	if (color.a > 20 && i == 0) {
		color.a = color.a - 3;
		sfSprite_setColor(sprite, color);
	}
	if (color.a <= 20)
		i = 1;
	if (color.a < 250 && i == 1) {
		color.a = color.a + 3;
		sfSprite_setColor(sprite, color);
	}
	if (color.a >= 250)
		i = 0;
}