/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** load_dungeon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rpg.h"
#include "my.h"

static char *concat_path(char *dir, char *file)
{
	char *final = malloc(my_strlen(dir) + my_strlen(file) + 1);

	my_strcpy(final, dir);
	my_strcat(final, file);
	return (final);
}

static linked_list_t *load_dungeon_rooms(char *path, sfTexture **text_bank)
{
	char **rooms_path = get_content_of_dir_with_ext(path, ".room");
	linked_list_t *list = NULL;
	room_t *room = NULL;
	char *f_path = NULL;

	if (rooms_path == NULL)
		return (NULL);
	for (int i = 0; rooms_path[i] != NULL; i++) {
		f_path = concat_path(path, rooms_path[i]);
		if (f_path == NULL)
			return (NULL);
		room = load_room(f_path, text_bank);
		if (room == NULL || !my_list_add(&list, room))
			return (NULL);
		free(f_path);
	}
	free_2d_arr(rooms_path);
	return (list);
}

static int get_dungeon_file_fd(char *path)
{
	char **files = get_content_of_dir_with_ext(path, ".dungeon");
	int fd = -1;
	char *f_path = NULL;

	if (files == NULL)
		return (-1);
	f_path = concat_path(path, files[0]);
	fd = open(f_path, O_RDONLY);
	free_2d_arr(files);
	free(f_path);
	return (fd);
}

static room_t *get_first_room(linked_list_t *rooms)
{
	linked_list_t *list = rooms;
	room_t *room = NULL;

	for (; list != NULL; list = list->next) {
		room = list->data;
		if (my_strcmp(room->name, "hall") == 0)
			return (room);
	}
	return (NULL);
}

room_t *load_dungeon(char *path, sfTexture **text_bank, linked_list_t **rooms)
{
	char *line = NULL;
	int fd = get_dungeon_file_fd(path);
	char **arg = NULL;
	room_t *room = NULL;

	*rooms = load_dungeon_rooms(path, text_bank);
	if (*rooms == NULL || fd == -1)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL) {
		arg = split_by(line, ':');
		if (arg == NULL)
			return (NULL);
		room = get_room_by_name(arg[0], *rooms);
		for (int i = 1; arg[i] != NULL; i++)
			if (!my_list_add(&room->crosspoint,
					get_room_by_name(arg[i], *rooms)))
				return (NULL);
		free_mem(line, arg);
	}
	return (get_first_room(*rooms));
}
