/*
** EPITECH PROJECT, 2018
** rp
** File description:
** sound box initializer
*/

#include "my.h"
#include "rpg.h"

sfMusic **load_music(void)
{
	sfMusic **soundbox;
	char **path = read_file("config/sound_path");
	int i = 0;

	if (path == NULL)
		return (NULL);
	soundbox = malloc(sizeof(sfMusic *) * (tab_len(path) + 1));
	if (soundbox == NULL)
		return (NULL);
	for (; i < tab_len(path); i++) {
		soundbox[i] = sfMusic_createFromFile(path[i]);
		if (soundbox[i] == NULL)
			return (NULL);
	}
	soundbox[i] = NULL;
	free_2d_arr(path);
	return (soundbox);
}
