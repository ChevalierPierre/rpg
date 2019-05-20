/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** trigger
*/

#include "rpg.h"
#include "my.h"

static int test_trigger(character_t *player, entity_t *ent)
{
	sfVector2f obj_a[2] = {{ent->pos.x, ent->pos.y},
			    {ent->pos.x + SCALING, ent->pos.y + SCALING}};
	sfVector2f *obj_b = get_character_hitbox(player);
	int ret = 0;

	ret = test_collision(obj_a, obj_b);
	free(obj_b);
	return (ret);
}

static void entity_actions(entity_t *ent, character_t *player,
			int *button, sfMusic **soundbox)
{
	if (ent->type == 'o' && test_trigger(player, ent)) {
		*button += 1;
		ent->type = 'x';
		sfMusic_play(soundbox[9]);
	} if (ent->type == 'W' && *button == 2) {
		ent->type = '!';
		sfMusic_play(soundbox[10]);
	} if (ent->type == 'K' && test_trigger(player, ent)) {
		ent->type = '!';
		player->key = 1;
		sfMusic_play(soundbox[2]);
	} if (player->key == 1 && ent->type == '?' &&
		test_trigger(player, ent)) {
		sfMusic_play(soundbox[8]);
		ent->type = '!';
	}
}

void trigger_button(character_t *player, room_t *room, sfMusic **soundbox)
{
	linked_list_t *list = room->entity;
	entity_t *ent = NULL;
	static int button = 0;

	for (; list != NULL; list = list->next) {
		ent = list->data;
		entity_actions(ent, player, &button, soundbox);
	}
}

void set_sprite(sfSprite *sprite, sfVector2f pos, sfVector2f scale)
{
	sfSprite_setScale(sprite, scale);
	sfSprite_setPosition(sprite, pos);
}

void free_mem(char *a, char **b)
{
	free_2d_arr(b);
	free(a);
}
