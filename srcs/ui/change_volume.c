/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu
*/

#include "rpg.h"
#include "menu.h"

void change_volume(window_t window, menu_t *menu)
{
	if (window.event.key.code == sfKeyLeft && menu->mode == 2
		&& menu->volume > 0) {
		menu->volume -= 5;
		sfMusic_setVolume(menu->music, menu->volume);
		sfSprite_move(menu->option.cursor.sprite, (sfVector2f){-17, 0});
	} else if (window.event.key.code == sfKeyRight && menu->mode == 2
	&& menu->volume < 100) {
		menu->volume += 5;
		sfMusic_setVolume(menu->music, menu->volume);
		sfSprite_move(menu->option.cursor.sprite, (sfVector2f){17, 0});
	}
}
