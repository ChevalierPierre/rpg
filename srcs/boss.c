/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** boss room
*/

#include "rpg.h"

static int end(linked_list_t *mobs, rpg_t *rpg)
{
	if (mobs == NULL) {
		sfMusic_stop(rpg->soundbox[15]);
		write_text("config/text/end.text", rpg);
		wait(300);
		return (1);
	}
	return (0);
}

static void set_pos(rpg_t *rpg)
{
	sfVector2f pos = {924, 691};
	rpg->player->pos = pos;
	sfSprite_setPosition(rpg->player->moves, pos);
	sfSprite_setPosition(rpg->player->attack, pos);
}

int boss(rpg_t *rpg)
{
	int ret = -1;
	linked_list_t *mobs = NULL;

	set_pos(rpg);
	load_room_mob(rpg->boss, &mobs, rpg);
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		if (end(mobs, rpg))
			return (end_menu(rpg));
		test_close(rpg->window.window);
		sfRenderWindow_clear(rpg->window.window, sfBlack);
		disp_room(rpg->boss, rpg);
		process_mob(&mobs, rpg, rpg->boss);
		ret = process_player(rpg, rpg->boss, mobs);
		if (ret != -1)
			break;
		sfRenderWindow_display(rpg->window.window);
		rpg->location = 3;
	}
	free_all_mob(mobs);
	return (ret);
}
