/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** structures for rpg project
*/

#ifndef STRUCT_H
#define STRUCT_H

#include "linked_list.h"
#include "ui.h"

static const float SCALING = 25;
static const float TEXT_SIZE = 400;
static const sfVector2f WIN_SIZE = {1920, 1000};
static const int WALL_SIZE = 60;
static const int HIT_RANGE = 50;
static const int EXPLODE = 3;

static const int PLAYER = 1;
static const int MOB = 2;

typedef struct event_s
{
	int type;
	sfSprite *sprite;
	sfClock *clock;
	int anim[2];
}event_t;

typedef struct character_s
{
	int type;
	int anim_move[2];
	int anim_atck[2];
	int dir;
	int speed;
	int life;
	int godmod;
	sfIntRect collider;
	sfIntRect rect_m;
	sfIntRect rect_a;
	sfSprite *moves;
	sfSprite *attack;
	sfVector2f pos;
	sfClock *clock;
	int gold;
	int key;
	int potions;
}character_t;

typedef struct anim_s
{
	sfRenderWindow *window;
	character_t *self;
}anim_t;

typedef struct entity_s
{
	int type;
	sfVector2f pos;
	sfVector2f coord;
}entity_t;

typedef struct window_s
{
	sfVideoMode mode;
	sfRenderWindow *window;
	sfEvent event;
}window_t;

typedef struct room_s
{
	char *name;
	char *text;
	sfVector2f size;
	sfSprite *gnd;
	sfSprite *wall;
	sfSprite *door;
	linked_list_t *entity;
	linked_list_t *exit;
	linked_list_t *crosspoint;
}room_t;

typedef struct rpg_s
{
	sfTexture **texture_bank;
	room_t *tavern;
	room_t *boss;
	sfSprite **utils_sprite;
	linked_list_t *events;
	window_t window;
	character_t *player;
	pause_t *pause;
	menu_t *menu;
	sfMusic **soundbox;
	int power;
	int location;
}rpg_t;

#endif
