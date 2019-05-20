/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** mob hurt
*/

#include "rpg.h"

static sfVector2f get_knockback_coef(character_t *mob)
{
	if (mob->dir == 0)
		return ((sfVector2f){1, 0});
	if (mob->dir == 1)
		return ((sfVector2f){-1, 0});
	if (mob->dir == 2)
		return ((sfVector2f){0, 1});
	if (mob->dir == 3)
		return ((sfVector2f){0, -1});
	return ((sfVector2f){0, 1});
}

void mob_hurt(character_t *mob)
{
	static sfVector2f coef;

	if (mob->godmod == 0)
		return;
	if (mob->godmod == 16) {
		coef = get_knockback_coef(mob);
	}
	mob->pos.x += 8 * coef.x;
	mob->pos.y += 8 * coef.y;
}
