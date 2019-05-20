/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** run a dungeon
*/

#include <stdlib.h>
#include "rpg.h"
#include "my.h"

void set_player_pos(room_t *dungeon, character_t *player)
{
	sfVector2f room_pos = sfSprite_getPosition(dungeon->gnd);
	sfVector2f pos = {dungeon->size.x + (room_pos.x / 2),
			dungeon->size.y + room_pos.y - 70};

	sfSprite_setPosition(player->moves, pos);
	player->pos = pos;
}

static void free_dungeon(linked_list_t *all_rooms, linked_list_t *mobs)
{
	linked_list_t *list = all_rooms;
	room_t *to_free = NULL;

	for (; list != NULL; list = list->next) {
		to_free = list->data;
		free(to_free->name);
		sfSprite_destroy(to_free->gnd);
		sfSprite_destroy(to_free->wall);
		sfSprite_destroy(to_free->door);
		free_entity(to_free->entity);
		free_entity(to_free->exit);
		my_list_delete(&to_free->crosspoint, NULL);
		free(to_free);
	}
	free_all_mob(mobs);
	my_list_delete(&all_rooms, NULL);
}

static void process_dungeon(room_t **actual_room, linked_list_t **mobs,
			rpg_t *rpg)
{
	static int buf = 0;

	test_close(rpg->window.window);
	sfRenderWindow_clear(rpg->window.window, sfBlack);
	disp_room(*actual_room, rpg);
	*actual_room = switch_room(*actual_room, rpg, mobs);
	process_mob(mobs, rpg, *actual_room);
	trigger_button(rpg->player, *actual_room, rpg->soundbox);
	if (buf == 0 && my_strcmp((*actual_room)->name, "boss") == 0
	&& *mobs == NULL) {
		write_text("config/text/boss.text", rpg);
		rpg->power = 1;
		buf = 1;
	}
}

int run_dungeon(rpg_t *rpg)
{
	linked_list_t *all_room = NULL;
	room_t *dungeon = load_dungeon("config/dungeon/dragons_cave/",
				rpg->texture_bank, &all_room);
	room_t *actual_room;
	linked_list_t *mobs = NULL;
	int ret = -1;

	if (dungeon == NULL)
		return (-1);
	actual_room = dungeon;
	set_player_pos(dungeon, rpg->player);
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		process_dungeon(&actual_room, &mobs, rpg);
		if ((ret = process_player(rpg, actual_room, mobs)) != -1)
			break;
		sfRenderWindow_display(rpg->window.window);
	}
	free_dungeon(all_room, mobs);
	return (ret);
}
