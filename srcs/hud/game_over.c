/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** game over screen
*/

#include "rpg.h"

int interact_button(rpg_t *rpg, sfVector2f hb1[2], sfVector2f hb2[2])
{
	sfVector2i mouse = sfMouse_getPosition((sfWindow *) rpg->window.window);
	int a = 0;

	if (mouse.x > hb1[0].x && mouse.x < hb1[1].x &&
	mouse.y > hb1[0].y && mouse.y < hb1[1].y) {
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[22], NULL);
		a = 1;
	} if (mouse.x > hb2[0].x && mouse.x < hb2[1].x &&
	mouse.y > hb2[0].y && mouse.y < hb2[1].y) {
		sfRenderWindow_drawSprite(rpg->window.window,
					  rpg->utils_sprite[23], NULL);
		a = 2;
	} if (a == 1 && sfMouse_isButtonPressed(sfMouseLeft))
		return (0);
	if (a == 2 && sfMouse_isButtonPressed(sfMouseLeft))
		return (-2);
	return (1);
}

int game_over(rpg_t *rpg)
{
	int ret = 1;
	sfVector2f hb1[2] = {{725, 568}, {1159, 692}};
	sfVector2f hb2[2] = {{725, 755}, {1159, 879}};

	sfMusic_stop(rpg->soundbox[11]);
	sfMusic_stop(rpg->soundbox[12]);
	sfMusic_play(rpg->soundbox[14]);
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		test_close(rpg->window.window);
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[21], NULL);
		ret = interact_button(rpg, hb1, hb2);
		if (ret != 1)
			break;
		sfRenderWindow_display(rpg->window.window);
	}
	return (ret);
}
