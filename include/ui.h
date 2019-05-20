/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** structures for rpg project
*/

#ifndef UI_H
#define UI_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct sprite_s
{
	sfClock *clock;
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
	sfVector2f move;
	sfIntRect rect;
	sfColor color;
}sprite_t;

typedef struct background_s
{
	sfSprite *sprite;
	sfTexture *texture;
}background_t;

typedef struct cloud_s
{
	sprite_t cloud;
	struct cloud_s *next;
	struct cloud_s *back;
}cloud_t;

typedef struct link_s
{
	cloud_t *begin;
	cloud_t *end;
}link_t;

typedef struct option_s
{
	sprite_t volume;
	sprite_t cursor;
	sprite_t fullscreen;
	sprite_t check;
	sprite_t title;
	sprite_t press_back;
}option_t;

typedef struct pause_s
{
	sprite_t title;
	sprite_t button[3];
	background_t back;
}pause_t;

typedef struct menu_s
{
	int volume;
	int mode;
	sfClock *clock;
	sfMusic *music;
	link_t link;
	cloud_t cloud;
	background_t back;
	sprite_t title;
	sprite_t start;
	sprite_t button[3];
	option_t option;
}menu_t;

#endif
