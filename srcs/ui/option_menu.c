/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu
*/

#include "rpg.h"
#include "menu.h"

option_t *init_option(option_t *option)
{
	option->title = *init_sprite(&option->title
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){200, 100}, (sfIntRect){0, 1260, 450, 220});
	init_sprite_color(&option->title, (sfColor){255, 255, 255, 0});
	option->volume = *init_sprite(&option->volume
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){500, 400}, (sfIntRect){1250, 0, 850, 225});
	sfSprite_setScale(option->volume.sprite, (sfVector2f){0.7, 0.7});
	init_sprite_color(&option->volume, (sfColor){255, 255, 255, 0});
	option->cursor = *init_sprite(&option->cursor
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){1035, 447}, (sfIntRect){1250, 225, 50, 125});
	sfSprite_setScale(option->cursor.sprite, (sfVector2f){0.7, 0.7});
	init_sprite_color(&option->cursor, (sfColor){255, 255, 255, 0});
	init_fullscreen(option);
	option->press_back = *init_sprite(&option->press_back
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){1400, 820}, (sfIntRect){1250, 670, 430, 100});
	init_sprite_color(&option->press_back, (sfColor){255, 255, 255, 0});
	return option;
}

void display_option(menu_t *menu)
{
	smooth_transparent(&menu->button[0], 10);
	smooth_transparent(&menu->button[1], 10);
	smooth_transparent(&menu->button[2], 10);
	smooth_transparent(&menu->title, 10);
	smooth_get_color(&menu->option.title);
	smooth_get_color(&menu->option.volume);
	smooth_get_color(&menu->option.cursor);
	smooth_get_color(&menu->option.fullscreen);
	smooth_get_color(&menu->option.check);
	smooth_get_color(&menu->option.press_back);
}

void display_main_menu(menu_t *menu)
{
	smooth_get_color(&menu->button[0]);
	smooth_get_color(&menu->button[1]);
	smooth_get_color(&menu->button[2]);
	smooth_get_color(&menu->title);
	smooth_transparent(&menu->option.title, 15);
	smooth_transparent(&menu->option.volume, 15);
	smooth_transparent(&menu->option.cursor, 15);
	smooth_transparent(&menu->option.fullscreen, 15);
	smooth_transparent(&menu->option.check, 15);
	smooth_transparent(&menu->option.press_back, 15);
}

void start_option(menu_t *menu)
{
	if (menu->mode == 2) {
		display_option(menu);
	} else if (menu->mode == 1) {
		display_main_menu(menu);
	}
}

void starting_press(menu_t *menu)
{
	if (menu->mode == 1) {
		smooth_transparent(&menu->start, 8);
		smooth_get_color(&menu->button[0]);
		smooth_get_color(&menu->button[1]);
		smooth_get_color(&menu->button[2]);
	} else if (menu->mode == 0)
		smooth_blink(menu->start.sprite);
}
