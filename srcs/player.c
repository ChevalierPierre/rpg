/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** player functions
*/

#include "rpg.h"
#include "menu.h"

static void set_player_attributes(character_t *player)
{
	player->rect_m = create_rect(50, 59, 0, 0);
	player->rect_a = create_rect(68, 78, 0, 0);
	player->collider = create_rect(12, 15, 50, 58);
	player->anim_move[0] = 0;
	player->anim_move[1] = 8;
	player->anim_atck[0] = 0;
	player->anim_atck[1] = 6;
	player->gold = 0;
	player->speed = 4;
	player->godmod = 0;
	player->life = 10;
	player->dir = 0;
	player->potions = 4;
	player->key = 0;
}

character_t *init_player(sfTexture **texture_bank)
{
	character_t *player = malloc(sizeof(character_t));
	sfSprite *move = sfSprite_create();
	sfSprite *attack = sfSprite_create();
	sfVector2f pos = {WIN_SIZE.x / 2, WIN_SIZE.y / 2};

	if (player == NULL || move == NULL || attack == NULL)
		return (NULL);
	sfSprite_setTexture(move, texture_bank[25], sfTrue);
	sfSprite_setTexture(attack, texture_bank[26], sfTrue);
	sfSprite_setScale(move, (sfVector2f){1.5, 1.5});
	sfSprite_setScale(attack, (sfVector2f){1.5, 1.5});
	player->type = PLAYER;
	player->pos = pos;
	player->moves = move;
	player->attack = attack;
	set_player_attributes(player);
	player->clock = sfClock_create();
	if (!player->clock || !player->moves || !player->attack)
		return (NULL);
	return (player);
}

int process_player(rpg_t *rpg, room_t *room, linked_list_t *mobs)
{
	int ret = -1;

	move_player(rpg, room);
	player_attack(rpg->player, mobs, rpg);
	if (sfKeyboard_isKeyPressed(sfKeyI)) {
		sfMusic_play(rpg->soundbox[3]);
		display_inventory(rpg);
	} if (sfKeyboard_isKeyPressed(sfKeyM)) {
		sfMusic_play(rpg->soundbox[6]);
		ret = draw_map(rpg);
		wait(300);
	} if (rpg->player->life <= 0)
		  ret = game_over(rpg);
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		ret = pause_loop(rpg);
		wait(300);
	} if (rpg->player->godmod != 0)
		rpg->player->godmod--;
	draw_hud(rpg);
	return (ret);
}
