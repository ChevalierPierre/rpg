/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** pause menu
*/

#include "rpg.h"
#include "menu.h"

int pause_navigation(window_t window, sprite_t *button)
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
			button[i].rect.left += 1070;
		else
			button[i].rect.left = 0;
		sfSprite_setTextureRect(button[i].sprite, button[i].rect);
	}
	return current_select;
}

int manage_pause(window_t window, pause_t *pause)
{
	if (window.event.type == sfEvtKeyReleased) {
		pause_navigation(window, pause->button);
		if (window.event.key.code == sfKeyReturn &&
		pause_navigation(window, pause->button) == 2)
			return -1;
		if (window.event.key.code == sfKeyReturn &&
		pause_navigation(window, pause->button) == 1)
			return 0;
		if (window.event.key.code == sfKeyReturn &&
		pause_navigation(window, pause->button) == 0)
			return 1;
	}
	return 42;
}

int event_pause(window_t window, pause_t *pause)
{
	int return_value = 0;

	while (sfRenderWindow_pollEvent(window.window, &(window.event))) {
		if (window.event.type == sfEvtClosed)
			sfRenderWindow_close(window.window);
		return_value = manage_pause(window, pause);
		if (return_value == 0)
			return 0;
		if (return_value == -1)
			return -1;
		if (return_value == 1)
			return 1;
	}
	return 42;
}

int pause_loop(rpg_t *rpg)
{
	int return_value;

	rpg->pause = init_pause_menu();
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		return_value = event_pause(rpg->window, rpg->pause);
		if (return_value == -1) {
			destroy_pause(rpg->pause);
			return (-2);
		} if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
		return_value == 1) {
			destroy_pause(rpg->pause);
			return (-1);
		} else if (return_value == 0) {
			destroy_pause(rpg->pause);
			return (0);
		}
		display_pause(rpg->pause);
		draw_pause(rpg->window.window, rpg->pause);
	}
	return (-1);
}
