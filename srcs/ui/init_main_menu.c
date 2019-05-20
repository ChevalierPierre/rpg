/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** initialisation functions
*/

#include "menu.h"
#include "rpg.h"

sprite_t *init_sprite_color(sprite_t *sprite, sfColor color)
{
	sprite->color = color;
	sfSprite_setColor(sprite->sprite, sprite->color);
	return sprite;
}

sprite_t *init_sprite(sprite_t *sprite, char *path, sfVector2f pos
	, sfIntRect rect)
{
	sprite->position.x = pos.x;
	sprite->position.y = pos.y;
	sprite->rect.top = rect.top;
	sprite->rect.left = rect.left;
	sprite->rect.width = rect.width;
	sprite->rect.height = rect.height;
	sprite->sprite = sfSprite_create();
	sprite->texture = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
	sfSprite_setPosition(sprite->sprite, pos);
	sfSprite_setTextureRect(sprite->sprite, sprite->rect);
	return sprite;
}

background_t *load_background(char *path)
{
	background_t *back = malloc(sizeof(background_t));

	back->texture = sfTexture_createFromFile(path, NULL);
	if (back->texture == NULL)
		return (NULL);
	back->sprite = sfSprite_create();
	sfSprite_setTexture(back->sprite, back->texture, sfTrue);
	sfSprite_setScale(back->sprite, (sfVector2f){0.318, 0.318});
	return back;
}

void init_main_button(menu_t *menu)
{
	menu->button[0] = *init_sprite(&menu->button[0]
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){1450.f, 500.f}, (sfIntRect){600, 0, 580, 228});
	sfSprite_setScale(menu->button[0].sprite, (sfVector2f){0.6, 0.6});
	menu->button[1] = *init_sprite(&menu->button[1]
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){1450.f, 640.f}, (sfIntRect){0, 240, 590, 190});
	sfSprite_setScale(menu->button[1].sprite, (sfVector2f){0.6, 0.6});
	menu->button[2] = *init_sprite(&menu->button[2]
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){1450.f, 750.f}, (sfIntRect){0, 420, 580, 200});
	sfSprite_setScale(menu->button[2].sprite, (sfVector2f){0.6, 0.6});
}

menu_t *init_main_menu(void)
{
	menu_t *menu = malloc(sizeof(menu_t));
	menu->link = *init_cloud();
	menu->back = *load_background(
		"assets/ui/sprites/Backgrounds/back_menu_rpg.png");
	menu->title = *init_sprite(&menu->title
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	, (sfVector2f){355.f, 100.f}, (sfIntRect){0, 915, 1260, 350});
	menu->start = *init_sprite(&menu->start
	, "assets/ui/sprites/Backgrounds/button_main_menu.png"
	,(sfVector2f){600.f, 550.f}, (sfIntRect){0, 670, 1145, 200});
	sfSprite_setScale(menu->start.sprite, (sfVector2f){0.6, 0.6});
	init_main_button(menu);
	menu->option = *init_option(&menu->option);
	return menu;
}
