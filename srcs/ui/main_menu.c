/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu
*/

#include "rpg.h"
#include "menu.h"

int event_menu(window_t window, menu_t *menu)
{
	int return_value = 0;

	while (sfRenderWindow_pollEvent(window.window, &(window.event))) {
		if (window.event.type == sfEvtClosed)
			sfRenderWindow_close(window.window);
		return_value = manage_button(window, menu);
		if (return_value == -1)
			return -1;
		else if (return_value == 1)
			return 1;
	}
	return 0;
}

void init_alpha_sprite(menu_t *menu)
{
	init_sprite_color(&menu->title, (sfColor){255, 255, 255, 255});
	init_sprite_color(&menu->start, (sfColor){255, 255, 255, 255});
	init_sprite_color(&menu->button[0], (sfColor){255, 255, 255, 0});
	init_sprite_color(&menu->button[1], (sfColor){255, 255, 255, 0});
	init_sprite_color(&menu->button[2], (sfColor){255, 255, 255, 0});
}

void init_menu_value(rpg_t *rpg)
{
	rpg->menu->volume = 100;
	rpg->menu->mode = 0;
	rpg->menu->clock = sfClock_create();
	rpg->menu->music = sfMusic_createFromFile("assets/music/main_menu.ogg");
}

int menu_loop(rpg_t *rpg)
{
	int return_value;

	init_alpha_sprite(rpg->menu);
	init_menu_value(rpg);
	sfMusic_setLoop(rpg->menu->music, sfTrue);
	sfMusic_play(rpg->menu->music);
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		return_value = event_menu(rpg->window, rpg->menu);
		if (return_value == -1)
			return -2;
		else if (return_value == 1) {
			sfMusic_stop(rpg->menu->music);
			return 1;
		}
		start_option(rpg->menu);
		starting_press(rpg->menu);
		clouds_gestion(rpg->menu);
		draw_menu(rpg->window.window, rpg->menu);
	}
	return -2;
}
