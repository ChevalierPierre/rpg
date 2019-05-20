/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity functions
*/

#include <stdlib.h>
#include "rpg.h"
#include "my.h"

void free_entity(linked_list_t *entity)
{
	linked_list_t *list = entity;
	entity_t *ent = NULL;

	for (; list != NULL; list = list->next) {
		ent = list->data;
		free(ent);
	}
	my_list_delete(&entity, NULL);
}

sfVector2f convert_pos(sfVector2f old, float scaling)
{
	sfVector2f new;

	new.x = old.x * scaling;
	new.y = old.y * scaling;
	return (new);
}

entity_t *get_entity(int x, int y, char **map, room_t *room)
{
	entity_t *entity = malloc(sizeof(entity_t));
	sfVector2f pos;

	pos.x = x;
	pos.y = y;
	if (entity == NULL)
		return (NULL);
	pos = convert_pos(pos, SCALING);
	pos.x += sfSprite_getPosition(room->gnd).x;
	pos.y += sfSprite_getPosition(room->gnd).y;
	entity->pos = pos;
	entity->coord = (sfVector2f){x, y};
	entity->type = map[y + 3][x];
	return (entity);
}

linked_list_t *get_room_entity(char **map, room_t *room)
{
	linked_list_t *entity = NULL;
	entity_t *ent = NULL;

	for (int y = 3; map[y] != NULL; y++) {
		for (int x = 0; map[y][x] != '\0'; x++) {
			if (map[y][x] != ' ' && map[y][x] != '*'
			&& !my_char_isnum(map[y][x])
			&& (ent = get_entity(x, y - 3, map, room)))
				my_list_add(&entity, ent);
		}
	}
	return (entity);
}

sfSprite *load_door_sprite(sfTexture **texture_bank)
{
	sfSprite *sprite = sfSprite_create();
	sfVector2f scale = {(WALL_SIZE / 2) / TEXT_SIZE, (WALL_SIZE / 2) /
			TEXT_SIZE};

	sfSprite_setTexture(sprite, texture_bank[29], sfTrue);
	sfSprite_setScale(sprite, scale);
	return (sprite);
}
