/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** creating mob entity
*/

#include "rpg.h"

character_t *create_mob(sfTexture **texture_bank, sfVector2f pos)
{
	character_t *mob = malloc(sizeof(character_t));
	sfSprite *move = sfSprite_create();

	if (mob == NULL || move == NULL)
		return (NULL);
	sfSprite_setTexture(move, texture_bank[32], sfTrue);
	mob->moves = move;
	mob->type = MOB;
	mob->pos = pos;
	mob->rect_m = create_rect(70, 82, 0, 0);
	mob->collider = create_rect(21, 2, 38, 57);
	mob->anim_move[0] = 0;
	mob->anim_move[1] = 3;
	set_mob_attributes(mob);
	mob->clock = sfClock_create();
	if (mob->clock == NULL || mob->moves == NULL)
		return (NULL);
	return (mob);
}

static sfVector2f check_direction(character_t *b, character_t *a)
{
	sfVector2f dir;
	sfVector2f vect;

	vect = (sfVector2f){b->pos.x - a->pos.x, b->pos.y - a->pos.y};
	if (vect.x < 0)
		dir.x = 0;
	else
		dir.x = 1;
	if (vect.y < 0)
		dir.y = 2;
	else
		dir.y = 3;
	return (dir);
}

void move_mob(rpg_t *rpg, room_t *room, character_t *mob, linked_list_t *mobs)
{
	sfVector2f dir = check_direction(rpg->player, mob);

	if (mob->pos.y < rpg->player->pos.y || mob->pos.y > rpg->player->pos.y
	+ rpg->player->collider.top)
		move_character((anim_t){rpg->window.window, mob}, dir.y,
			room, mobs);
	else
		move_character((anim_t){rpg->window.window, mob}, dir.x,
			room, mobs);
}

void process_mob(linked_list_t **mobs, rpg_t *rpg, room_t *room)
{
	character_t *ent = NULL;

	for (linked_list_t *list = *mobs; list != NULL; list = list->next) {
		ent = list->data;
		mob_hurt(ent);
		if (ent->life <= 0) {
			sfMusic_play(rpg->soundbox[1]);
			mob_death(rpg, ent);
			destroy_mob(ent);
			my_list_delete(mobs, list);
			rpg->player->gold += 2;
			continue;
		}
		move_mob(rpg, room, ent, *mobs);
		if (ent->godmod != 0)
			ent->godmod--;
		else
			mob_attack(ent, rpg->player, rpg->soundbox);
	}
	display_event(rpg);
}

int load_room_mob(room_t *room, linked_list_t **mobs, rpg_t *rpg)
{
	linked_list_t *list = room->entity;
	entity_t *ent;
	character_t *mob = NULL;

	for (; list != NULL; list = list->next) {
		ent = list->data;
		if (ent->type == 'M' &&
		(mob = create_mob(rpg->texture_bank, ent->pos)) == NULL)
			return (0);
		if (ent->type == 'M')
			my_list_add(mobs, mob);
	}
	return (1);
}
