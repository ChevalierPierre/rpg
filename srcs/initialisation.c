/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** initialisation functions
*/

#include "rpg.h"
#include "my.h"
#include "menu.h"

void free_rpg_struct(rpg_t *rpg)
{
	for (int i = 0; rpg->texture_bank[i] != NULL; i++)
		sfTexture_destroy(rpg->texture_bank[i]);
	for (int i = 0; rpg->utils_sprite[i] != NULL; i++)
		sfSprite_destroy(rpg->utils_sprite[i]);
	for (int i = 0; rpg->soundbox[i] != NULL; i++)
		sfMusic_destroy(rpg->soundbox[i]);
	free(rpg->tavern->name);
	sfSprite_destroy(rpg->tavern->gnd);
	sfSprite_destroy(rpg->tavern->wall);
	sfSprite_destroy(rpg->tavern->door);
	free_entity(rpg->tavern->entity);
	free_entity(rpg->tavern->exit);
	free(rpg->tavern);
	sfSprite_destroy(rpg->player->moves);
	sfSprite_destroy(rpg->player->attack);
	sfClock_destroy(rpg->player->clock);
	free(rpg->player);
	destroy_menu(rpg->window.window, rpg->menu);
	free(rpg);
}

sfRenderWindow *create_window(void)
{
	sfVideoMode vm = {WIN_SIZE.x, WIN_SIZE.y, 32};
	sfRenderWindow *window = sfRenderWindow_create(vm, "MY_RPG",
						sfClose, NULL);

	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}

static int set_rpg_attributes(rpg_t *rpg, room_t *room, character_t *player,
			sfTexture **texts)
{
	rpg->player = player;
	rpg->tavern = room;
	rpg->events = NULL;
	rpg->power = 0;
	rpg->location = 0;
	rpg->texture_bank = texts;
	rpg->boss = load_room("./config/single_room/final_boss.room", texts);
	if (rpg->boss == NULL)
		return (0);
	return (1);
}

rpg_t *init_game_struct(void)
{
	rpg_t *rpg = malloc(sizeof(rpg_t));
	room_t *room;
	sfTexture **texts = load_texture();
	window_t win = init_window();
	character_t *player;
	sfMusic **soundbox = load_music();

	if (!rpg || !win.window || !texts || !soundbox)
		return (NULL);
	room = load_room("./config/single_room/tavern.room", texts);
	player = init_player(texts);
	rpg->utils_sprite = create_utils_sprite(texts);
	rpg->menu = init_main_menu();
	if (!room || !player || !rpg->utils_sprite || !rpg->menu)
		return (NULL);
	if (!set_rpg_attributes(rpg, room, player, texts))
		return (NULL);
	rpg->soundbox = soundbox;
	rpg->window = win;
	return (rpg);
}
