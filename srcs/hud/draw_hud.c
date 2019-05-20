/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** draw hud
*/

#include "rpg.h"

static void life(rpg_t *rpg)
{
	sfIntRect rect = create_rect(146, 28, 0, 0);

	rect.top = rect.height * (rpg->player->life - 1);
	sfSprite_setTextureRect(rpg->utils_sprite[11], rect);
	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[11], NULL);
}

static void potion(rpg_t *rpg)
{
	sfIntRect rect = create_rect(126, 123, 0, 0);
	static int delay = 0;

	if (rpg->player->potions != 0)
		rect.left = rect.width;
	if (sfKeyboard_isKeyPressed(sfKeyC) && rpg->player->potions != 0
	&& rpg->player->life != 10) {
		sfMusic_play(rpg->soundbox[4]);
		delay = 16;
		rpg->player->potions--;
		rpg->player->life = 10;
		wait(200);
	}
	if (delay != 0) {
		rect.left = rect.width * 2;
		delay--;
	}
	sfSprite_setTextureRect(rpg->utils_sprite[9], rect);
	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[9], NULL);
}

static void hit(rpg_t *rpg)
{
	sfIntRect rect = create_rect(175, 169, 0, 0);

	if (rpg->player->anim_atck[0] != 0)
		rect.left = rect.width;
	sfSprite_setTextureRect(rpg->utils_sprite[8], rect);
	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[8], NULL);
}

void draw_hud(rpg_t *rpg)
{
	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[13], NULL);
	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[14], NULL);
	if (rpg->player->key == 1)
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[16], NULL);
	life(rpg);
	potion(rpg);
	hit(rpg);
}
