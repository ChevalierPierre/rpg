/*
** EPITECH PROJECT, 2018
** init_window
** File description:
** rpg
*/

#include "rpg.h"

window_t init_window(void)
{
	window_t window;

	window.mode.width = WIN_SIZE.x;
	window.mode.height = WIN_SIZE.y;
	window.mode.bitsPerPixel = 32;
	window.window = sfRenderWindow_create(window.mode, "MY_RPG"
	, sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window.window, 60);
	return (window);
}
