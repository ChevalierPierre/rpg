/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** crosspoint
*/

#include "rpg.h"
#include "menu.h"

int run_game(rpg_t *rpg)
{
	int ret = -1;
	static int i = 0;

	rpg->player->life = 10;
	set_player_pos(rpg->tavern, rpg->player);
	for (; sfRenderWindow_isOpen(rpg->window.window); i++) {
		process_tavern(rpg, i);
		ret = process_player(rpg, rpg->tavern, NULL);
		if (on_shop(rpg->tavern, rpg)) {
			shop(rpg);
			wait(300);
		} if (exit_tavern(rpg->tavern, rpg)) {
			sfMusic_play(rpg->soundbox[6]);
			ret = draw_map(rpg);
		} if (ret != -1)
			break;
		sfRenderWindow_display(rpg->window.window);
		rpg->location = 0;
	}
	return (ret);
}

static int location_scene(int loc)
{
	if (loc == 0)
		return (1);
	if (loc == 2)
		return (2);
	return (3);
}

static void play_music(int status, rpg_t *rpg)
{
	if (status == 1)
		sfMusic_play(rpg->soundbox[12]);
	if (status == 2)
		sfMusic_play(rpg->soundbox[11]);
	if (status == 3)
		sfMusic_play(rpg->soundbox[15]);
}

void my_rpg(rpg_t *rpg)
{
	int status = 0;
	int(*scenes[4]) (rpg_t *) = {&menu_loop, &run_game, &run_dungeon,
				&boss};

	sfMusic_setLoop(rpg->soundbox[11], sfTrue);
	sfMusic_setLoop(rpg->soundbox[12], sfTrue);
	sfMusic_setLoop(rpg->soundbox[15], sfTrue);
	while (status != -2 && sfRenderWindow_isOpen(rpg->window.window)) {
		status = scenes[status](rpg);
		if (status == 42)
			status = location_scene(rpg->location);
		sfMusic_stop(rpg->soundbox[11]);
		sfMusic_stop(rpg->soundbox[12]);
		sfMusic_stop(rpg->soundbox[15]);
		play_music(status, rpg);
		rpg->player->key = 0;
	}
	free_rpg_struct(rpg);
}
