/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** texture manager
*/

#include "rpg.h"
#include "my.h"

sfTexture **load_texture(void)
{
	sfTexture **text_bk;
	char **path = read_file("config/texture_path");
	int i = 0;

	if (path == NULL)
		return (NULL);
	text_bk = malloc(sizeof(sfTexture *) * (tab_len(path) + 1));
	if (text_bk == NULL)
		return (NULL);
	for (; i < tab_len(path); i++) {
		text_bk[i] = sfTexture_createFromFile(path[i], NULL);
		if (text_bk[i] == NULL)
			return (NULL);
	}
	text_bk[i] = NULL;
	free_2d_arr(path);
	return (text_bk);
}
