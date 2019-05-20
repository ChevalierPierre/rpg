/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** move player
*/

#include "rpg.h"

static void move_player2(rpg_t *rpg, room_t *room)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) &&
	rpg->player->anim_atck[0] == 0) {
		sfMusic_play(rpg->soundbox[5]);
		return (move_character((anim_t)
				{rpg->window.window, rpg->player}, 2,
				room, NULL));
	} if (sfKeyboard_isKeyPressed(sfKeyDown) &&
	rpg->player->anim_atck[0] == 0) {
		sfMusic_play(rpg->soundbox[5]);
		return (move_character((anim_t)
				{rpg->window.window, rpg->player}, 3,
				room, NULL));
	}
	display_static_character(rpg->window.window, rpg->player);
}

void move_player(rpg_t *rpg, room_t *room)
{
	if (rpg->player->anim_atck[0] != 0 ||
	sfKeyboard_isKeyPressed(sfKeySpace)) {
		sfMusic_play(rpg->soundbox[0]);
		return (character_attack(rpg->window.window, rpg->player));
	} if (sfKeyboard_isKeyPressed(sfKeyRight) &&
	rpg->player->anim_atck[0] == 0) {
		sfMusic_play(rpg->soundbox[5]);
		return (move_character((anim_t)
				{rpg->window.window, rpg->player}, 1,
				room, NULL));
	} if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
	rpg->player->anim_atck[0] == 0) {
		sfMusic_play(rpg->soundbox[5]);
		return (move_character((anim_t)
				{rpg->window.window, rpg->player},
				0, room, NULL));
	}
	return (move_player2(rpg, room));
}
