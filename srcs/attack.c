/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "rpg.h"

int test_hit(character_t *obj_a, character_t *obj_b, rpg_t *rpg)
{
	sfVector2f *hb_a;
	sfVector2f *hb_b;
	int ret = 0;

	(void)rpg;
	hb_a = get_attack_hitbox(obj_a);
	hb_b = get_character_hitbox(obj_b);
	ret = test_collision(hb_a, hb_b);
	free(hb_a);
	free(hb_b);
	return (ret);
}

void mob_attack(character_t *mob, character_t *player, sfMusic **soundbox)
{
	if (player->godmod == 0 && test_hit(mob, player, NULL)) {
		player->life--;
		player->godmod = 32;
		sfMusic_play(soundbox[7]);
	}
}

void player_attack(character_t *player, linked_list_t *mobs, rpg_t *rpg)
{
	linked_list_t *list = mobs;
	character_t *mob = NULL;

	ultimate_attack(rpg, mobs);
	if (player->anim_atck[0] == 0)
		return;
	for (; list != NULL; list = list->next) {
		mob = list->data;
		if (mob->godmod == 0 && test_hit(player, mob, rpg)) {
			mob->godmod = 16;
			mob->life--;
		}
	}
}
