/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** initialisation functions
*/

#include "menu.h"
#include "rpg.h"

void init_pause_button(pause_t *pause)
{
	pause->button[0] = *init_sprite(&pause->button[0]
	, "assets/ui/sprites/Backgrounds/pause_menu.png"
	, (sfVector2f){300, 400}, (sfIntRect){1070, 440, 700, 170});
	sfSprite_setScale(pause->button[0].sprite, (sfVector2f){0.6, 0.6});
	init_sprite_color(&pause->button[0], (sfColor){255, 255, 255, 0});
	pause->button[1] = *init_sprite(&pause->button[1]
	, "assets/ui/sprites/Backgrounds/pause_menu.png"
	, (sfVector2f){300, 550}, (sfIntRect){0, 660, 980, 170});
	sfSprite_setScale(pause->button[1].sprite, (sfVector2f){0.6, 0.6});
	init_sprite_color(&pause->button[1], (sfColor){255, 255, 255, 0});
	pause->button[2] = *init_sprite(&pause->button[2]
	, "assets/ui/sprites/Backgrounds/pause_menu.png"
	, (sfVector2f){300, 700}, (sfIntRect){0, 880, 580, 170});
	sfSprite_setScale(pause->button[2].sprite, (sfVector2f){0.6, 0.6});
	init_sprite_color(&pause->button[2], (sfColor){255, 255, 255, 0});

}

pause_t *init_pause_menu(void)
{
	pause_t *pause = malloc(sizeof(pause_t));
	pause->back = *load_background(
		"assets/ui/sprites/Backgrounds/back_menu_rpg.png");
	pause->title = *init_sprite(&pause->title
	, "assets/ui/sprites/Backgrounds/pause_menu.png"
	, (sfVector2f){100, 50}, (sfIntRect){0, 0, 900, 430});
	sfSprite_setScale(pause->title.sprite, (sfVector2f){0.6, 0.6});
	init_sprite_color(&pause->title, (sfColor){255, 255, 255, 0});
	init_pause_button(pause);
	return pause;
}
