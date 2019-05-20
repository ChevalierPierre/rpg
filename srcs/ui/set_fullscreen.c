/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** initialisation functions
*/

#include "rpg.h"
#include "menu.h"

void init_fullscreen(option_t *option)
{
	option->fullscreen = *init_sprite(&option->fullscreen
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){500, 600}, (sfIntRect){1250, 470, 445, 130});
	sfSprite_setScale(option->fullscreen.sprite, (sfVector2f){0.7, 0.7});
	init_sprite_color(&option->fullscreen, (sfColor){255, 255, 255, 0});
	option->check = *init_sprite(&option->check
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){900, 600}, (sfIntRect){1740, 470, 140, 140});
	sfSprite_setScale(option->check.sprite, (sfVector2f){0.7, 0.7});
	init_sprite_color(&option->check, (sfColor){255, 255, 255, 0});
}

void set_fullscreen_on(window_t window, option_t *option)
{
	option->check.rect.left = 1925;
	sfSprite_setTextureRect(option->check.sprite, option->check.rect);
	sfRenderWindow_destroy(window.window);
	sfRenderWindow_create(window.mode, "MY_RPG", sfFullscreen, NULL);
	sfRenderWindow_setFramerateLimit(window.window, 60);
}

void set_fullscreen_off(window_t window, option_t *option)
{
	option->check.rect.left = 1740;
	sfSprite_setTextureRect(option->check.sprite, option->check.rect);
	sfRenderWindow_destroy(window.window);
	sfRenderWindow_create(window.mode, "MY_RPG"
	, sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window.window, 60);
}

void set_fullscreen(menu_t *menu, option_t *option, window_t window)
{
	static int on = 0;

	if (on == 1) {
		option->check.rect.left = 1740;
		sfSprite_setTextureRect(option->check.sprite
		, option->check.rect);
	}
	if (window.event.key.code == sfKeyF && menu->mode == 2
	&& on == 0) {
		on = 1;
		set_fullscreen_on(window, option);
	} else if (window.event.key.code == sfKeyF && menu->mode == 2
	&& on == 1) {
		on = 0;
		set_fullscreen_off(window, option);
	}
}
