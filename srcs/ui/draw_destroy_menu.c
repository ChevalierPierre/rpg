/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** initialisation functions
*/

#include "rpg.h"
#include "menu.h"

void draw_option(sfRenderWindow *window, option_t *option)
{
	sfRenderWindow_drawSprite(window, option->title.sprite, NULL);
	sfRenderWindow_drawSprite(window, option->volume.sprite, NULL);
	sfRenderWindow_drawSprite(window, option->cursor.sprite, NULL);
	sfRenderWindow_drawSprite(window, option->fullscreen.sprite, NULL);
	sfRenderWindow_drawSprite(window, option->check.sprite, NULL);
	sfRenderWindow_drawSprite(window, option->press_back.sprite, NULL);
}

void destroy_menu(sfRenderWindow *window, menu_t *menu)
{
	sfTexture_destroy(menu->back.texture);
	sfSprite_destroy(menu->back.sprite);
	sfSprite_destroy(menu->title.sprite);
	sfSprite_destroy(menu->option.check.sprite);
	sfSprite_destroy(menu->option.fullscreen.sprite);
	sfSprite_destroy(menu->option.title.sprite);
	sfSprite_destroy(menu->option.volume.sprite);
	sfSprite_destroy(menu->option.cursor.sprite);
	sfSprite_destroy(menu->button[0].sprite);
	sfSprite_destroy(menu->button[1].sprite);
	sfSprite_destroy(menu->button[2].sprite);
	sfClock_destroy(menu->clock);
	sfMusic_destroy(menu->music);
	sfSprite_destroy(menu->start.sprite);
	sfSprite_destroy(menu->option.press_back.sprite);
	for (cloud_t *now = menu->link.begin; now; now = now->next)
		sfSprite_destroy(now->cloud.sprite);
	sfRenderWindow_destroy(window);
	free(menu);
}

void draw_menu(sfRenderWindow *window, menu_t *menu)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, menu->back.sprite, NULL);
	for (cloud_t *now = menu->link.begin; now != NULL; now = now->next)
		sfRenderWindow_drawSprite(window, now->cloud.sprite, NULL);
	sfRenderWindow_drawSprite(window, menu->title.sprite, NULL);
	sfRenderWindow_drawSprite(window, menu->start.sprite, NULL);
	draw_option(window, &menu->option);
	sfRenderWindow_drawSprite(window, menu->button[0].sprite, NULL);
	sfRenderWindow_drawSprite(window, menu->button[1].sprite, NULL);
	sfRenderWindow_drawSprite(window, menu->button[2].sprite, NULL);
	sfRenderWindow_display(window);
}
