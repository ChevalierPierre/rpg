/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** parse and generate a room
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "rpg.h"
#include "my.h"

static char **load_map(char *path)
{
	int fd = open(path, O_RDONLY);
	char **map = NULL;
	char *line = NULL;

	if (fd == -1)
		return (NULL);
	for (int i = 0; (line = get_next_line(fd)) != NULL; i++) {
		map = tab_realloc(map, 1);
		if (map == NULL)
			return (NULL);
		map[i] = line;
	}
	close(fd);
	return (map);
}

sfSprite *load_sprite(room_t *room, sfTexture **bank, char **map, char *type)
{
	sfSprite *sprite = sfSprite_create();
	char *sp_text_id = get_env_variable(map, type);
	sfVector2f pos = {(WIN_SIZE.x - room->size.x) / 2,
			(WIN_SIZE.y - room->size.y) / 2};
	sfVector2f ws = {room->size.x + WALL_SIZE, room->size.y + WALL_SIZE};
	sfVector2f scale = {room->size.x / TEXT_SIZE, room->size.y / TEXT_SIZE};

	if (!sprite || !sp_text_id || !my_isnum(sp_text_id))
		return (NULL);
	sfSprite_setTexture(sprite, bank[my_getnbr(sp_text_id)], sfTrue);
	if (my_strcmp(type, "WALL") == 0) {
		pos.x = (WIN_SIZE.x - ws.x) / 2;
		pos.y = (WIN_SIZE.y - ws.y) / 2;
		scale.x = ws.x / TEXT_SIZE;
		scale.y = ws.y / TEXT_SIZE;
		room->size.x -= WALL_SIZE / 2;
		room->size.y -= WALL_SIZE / 2;
	}
	set_sprite(sprite, pos, scale);
	return (sprite);
}

int set_room_exits(room_t *new_room, char **map)
{
	linked_list_t *exit = NULL;
	entity_t *ent = NULL;

	for (int y = 3; map[y] != NULL; y++) {
		for (int x = 0; map[y][x] != '\0'; x++) {
			if ((y == 3 || map[y + 1] == NULL || x == 0 ||
			map[y][x + 1] == '\0') && my_char_isnum(map[y][x])
			&& (ent = get_entity(x, y - 3, map, new_room)))
				my_list_add(&exit, ent);
		}
	}
	new_room->exit = exit;
	return (1);
}

sfVector2f get_room_size(char **map)
{
	sfVector2f size;

	size.x = my_strlen(map[3]);
	size.y = tab_len(&map[3]);
	return (convert_pos(size, SCALING));
}

room_t *load_room(char *path, sfTexture **texture_bank)
{
	room_t *new_room = malloc(sizeof(room_t));
	char **map = load_map(path);

	if (map == NULL || new_room == NULL)
		return (NULL);
	new_room->name = my_strdup(get_env_variable(map, "NAME"));
	if (new_room->name == NULL)
		return (NULL);
	new_room->size = get_room_size(map);
	new_room->crosspoint = NULL;
	new_room->door = load_door_sprite(texture_bank);
	new_room->gnd = load_sprite(new_room, texture_bank, map, "GND");
	new_room->wall = load_sprite(new_room, texture_bank, map, "WALL");
	if (!new_room->gnd || !new_room->wall ||
	!set_room_exits(new_room, map) || !new_room->door)
		return (NULL);
	new_room->entity = get_room_entity(map, new_room);
	free_2d_arr(map);
	return (new_room);
}
