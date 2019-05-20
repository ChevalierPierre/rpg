/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** end menu
*/

#include "rpg.h"

int end_menu(rpg_t *rpg)
{
	int ret = 1;
	sfVector2f hb1[2] = {{743, 57}, {1177, 181}};
	sfVector2f hb2[2] = {{743, 244}, {1177, 368}};

	sfMusic_play(rpg->soundbox[16]);
	sfSprite_setPosition(rpg->utils_sprite[22], (sfVector2f){743, 57});
	sfSprite_setPosition(rpg->utils_sprite[23], (sfVector2f){743, 244});
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		test_close(rpg->window.window);
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[24], NULL);
		ret = interact_button(rpg, hb1, hb2);
		if (ret != 1)
			break;
		sfRenderWindow_display(rpg->window.window);
	}
	sfSprite_setPosition(rpg->utils_sprite[22], (sfVector2f){725, 568});
	sfSprite_setPosition(rpg->utils_sprite[23], (sfVector2f){725, 755});
	return (ret);
}
