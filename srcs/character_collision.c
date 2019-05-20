/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** character collision
*/

#include "rpg.h"

int check_characters_collision(character_t *a, character_t *b, rpg_t *rpg)
{
	sfVector2f *obj_a = get_character_hitbox(a);
	sfVector2f pos = sfSprite_getPosition(b->moves);
	sfVector2f obj_b[2] = {pos, {pos.x + b->rect_m.width,
				pos.y + b->rect_m.height}};
	int ret;

	if (obj_a == NULL)
		return (0);
	ret = test_collision(obj_a, obj_b);
	sfSprite_setPosition(rpg->utils_sprite[1], obj_b[0]);
	sfRenderWindow_drawSprite(rpg->window.window, rpg->utils_sprite[1],
				NULL);
	sfSprite_setPosition(rpg->utils_sprite[1], obj_b[1]);
	sfRenderWindow_drawSprite(rpg->window.window, rpg->utils_sprite[1],
				NULL);
	free(obj_a);
	return (ret);
}
