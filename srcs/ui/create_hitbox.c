/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu
*/

#include "rpg.h"

int check_hitbox(sprite_t *sprite, point_t *point, int x, int y)
{
	if (mouse_pos->x <= sprite->position.x + x
	&& mouse_pos->x >= button->position.y
	&& mouse_pos->y >= button->position.y + y
	&& sfMouse_isButtonPressed(sfMouseLeft) == 1)
		return 1;
	return 0;
}