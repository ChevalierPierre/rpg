/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** particule generator
*/

#include "rpg.h"

static sfUint8 *generate_particles(void)
{
	sfUint8 *pxl = malloc(82 * 12 * 4);
	sfColor colors[3] = { {255, 170, 76, 255},
			{255, 43, 28, 255},
			{255, 85, 28, 255} };
	int col_id = 0;

	if (pxl == NULL)
		return (NULL);
	for (int i = 0; i < 82 * 12 * 4; i += 4) {
		if (rand() % 30 != 7)
			continue;
		col_id = rand() % 2;
		pxl[i] = colors[col_id].r;
		pxl[i + 1] = colors[col_id].g;
		pxl[i + 2] = colors[col_id].b;
		pxl[i + 3] = rand() % 255 + 110;
	}
	return (pxl);
}

void display_particles(rpg_t *rpg, sfVector2f pos)
{
	sfTexture *text = sfTexture_create(82, 12);
	sfSprite *sprite = sfSprite_create();
	sfUint8 *buf = generate_particles();

	if (text == NULL || sprite == NULL || buf == NULL)
		return;
	sfTexture_updateFromPixels(text, buf, 82, 12, 0, 0);
	sfSprite_setTexture(sprite, text, sfTrue);
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(rpg->window.window, sprite, NULL);
	sfSprite_destroy(sprite);
	sfTexture_destroy(text);
	free(buf);
}
