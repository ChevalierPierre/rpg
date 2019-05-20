/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** pause menu
*/

#include "rpg.h"
#include "menu.h"

void draw_pause(sfRenderWindow *window, pause_t *pause)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, pause->back.sprite, NULL);
	sfRenderWindow_drawSprite(window, pause->title.sprite, NULL);
	sfRenderWindow_drawSprite(window, pause->button[0].sprite, NULL);
	sfRenderWindow_drawSprite(window, pause->button[1].sprite, NULL);
	sfRenderWindow_drawSprite(window, pause->button[2].sprite, NULL);
	sfRenderWindow_display(window);
}

void destroy_pause(pause_t *pause)
{
	sfTexture_destroy(pause->back.texture);
	sfSprite_destroy(pause->title.sprite);
	sfSprite_destroy(pause->button[0].sprite);
	sfSprite_destroy(pause->button[1].sprite);
	sfSprite_destroy(pause->button[2].sprite);
}

void display_pause(pause_t *pause)
{
	smooth_get_color(&pause->title);
	smooth_get_color(&pause->button[0]);
	smooth_get_color(&pause->button[1]);
	smooth_get_color(&pause->button[2]);
}
