/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** ultimate attack
*/

#include "rpg.h"

static sfVector2f get_dir_vect(character_t *player)
{
	sfVector2f vect;

	if (player->dir == 0)
		vect = (sfVector2f){-1, 0};
	if (player->dir == 1)
		vect = (sfVector2f){1, 0};
	if (player->dir == 2)
		vect = (sfVector2f){0, -1};
	if (player->dir == 3)
		vect = (sfVector2f){0, 1};
	return (vect);
}

static void test_hit(linked_list_t *mobs, sfVector2f pos)
{
	linked_list_t *list = mobs;
	character_t *mob = NULL;
	sfVector2f obj_a[2] = {pos, {pos.x + 82, pos.y + 12}};
	sfVector2f *obj_b;

	for (; list != NULL; list = list->next) {
		mob = list->data;
		obj_b = get_character_hitbox(mob);
		if (obj_b != NULL && test_collision(obj_a, obj_b)) {
			mob->life -= 3;
			mob->godmod = 16;
			free(obj_b);
		}
	}
}

void ultimate_attack(rpg_t *rpg, linked_list_t *mobs)
{
	static int frame = 0;
	static sfVector2f pos;
	static sfVector2f dir;

	if (rpg->power != 1 || rpg->player->anim_atck[0] != 1)
		if (frame == 0)
			return;
	if (frame == 0) {
		frame = 100;
		pos = rpg->player->pos;
		dir = get_dir_vect(rpg->player);
	} if (frame % 2 == 0) {
		pos.x += 30 * dir.x;
		pos.y += 30 * dir.y;
	}
	display_particles(rpg, pos);
	test_hit(mobs, pos);
	frame--;
}
