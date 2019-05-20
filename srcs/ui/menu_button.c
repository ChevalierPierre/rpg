/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu
*/

#include "rpg.h"
#include "menu.h"

int menu_navigation(window_t window, sprite_t *button)
{
	int table_size = 3;
	static int current_select = 0;

	if (window.event.key.code == sfKeyDown)
		current_select = (current_select + 1) % table_size;
	else if (window.event.key.code == sfKeyUp) {
		current_select = (current_select - 1) % table_size;
		if (current_select < 0)
			current_select = 2;
	} else
		return current_select;
	for (int i = 0; i < table_size; i++) {
		if (i == current_select)
			button[i].rect.left += 600;
		else
			button[i].rect.left = 0;
		sfSprite_setTextureRect(button[i].sprite, button[i].rect);
	}
	return current_select;
}

void starting_mode(window_t window, menu_t *menu)
{
	if (window.event.key.code == sfKeyReturn && !menu->mode) {
		menu->mode = 1;
	} else if (menu->mode == 1)
		menu_navigation(window, menu->button);
}

void change_mode(window_t window, menu_t *menu)
{
	if (window.event.key.code == sfKeyReturn && menu->mode == 1
	&& menu_navigation(window, menu->button) == 1)
		menu->mode = 2;
	if (window.event.key.code == sfKeyEscape && menu->mode == 2)
		menu->mode = 1;
}

int manage_button(window_t window, menu_t *menu)
{
	if (window.event.type == sfEvtKeyReleased) {
		if (window.event.key.code == sfKeyReturn &&
		menu_navigation(window, menu->button) == 2 && menu->mode == 1)
			return -1;
		if (window.event.key.code == sfKeyReturn &&
		menu_navigation(window, menu->button) == 0 && menu->mode == 1)
			return 1;
		starting_mode(window, menu);
		change_mode(window, menu);
		change_volume(window, menu);
		set_fullscreen(menu, &menu->option, window);
	}
	return 0;
}
