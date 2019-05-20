/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory
*/

#include "rpg.h"
#include "my.h"

static void draw_potion(rpg_t *rpg)
{
	int pots = rpg->player->potions;
	sfVector2f vect = {125, 0};
	sfVector2f src = sfSprite_getPosition(rpg->utils_sprite[12]);

	for (; pots != 0; pots--) {
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[12], NULL);
		sfSprite_move(rpg->utils_sprite[12], vect);
	}
	sfSprite_setPosition(rpg->utils_sprite[12], src);
}

void display_inventory(rpg_t *rpg)
{
	sfText *txt = init_text(70, "assets/font/rpg.otf",
				(sfVector2f){570, 280},
				(sfColor){255, 173, 43, 255});

	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[2 + rpg->power], NULL);
	sfText_setString(txt, my_int_to_str(rpg->player->gold));
	draw_potion(rpg);
	sfRenderWindow_drawText(rpg->window.window, txt, NULL);
	sfRenderWindow_display(rpg->window.window);
	wait(200);
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		test_close(rpg->window.window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			break;
	}
	sfText_destroy(txt);
	wait(300);
}
