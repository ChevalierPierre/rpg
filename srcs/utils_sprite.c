/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** utils sprite initialisation
*/

#include "rpg.h"
#include "my.h"

static int create_sprite(sfSprite **sprite, sfTexture **texture_bank,
			char **info, int i)
{
	char **str_pos = NULL;

	*sprite = sfSprite_create();
	if (*sprite == NULL)
		return (0);
	sfSprite_setTexture(*sprite, texture_bank[i], sfTrue);
	str_pos = split_by(info[i] , ',');
	if (str_pos == NULL || tab_len(str_pos) != 2 ||
	!my_isnum(str_pos[0]) || !my_isnum(str_pos[1]))
		return (0);
	sfSprite_setPosition(*sprite, (sfVector2f){my_getnbr
				(str_pos[0]), my_getnbr(str_pos[1])});
	free_2d_arr(str_pos);
	return (1);
}

sfSprite **create_utils_sprite(sfTexture **texture_bank)
{
	char **info = read_file("config/utils_sprite_info");
	sfSprite **sprites = NULL;
	int i = 0;

	if (info == NULL)
		return (NULL);
	sprites = malloc(sizeof(sfSprite *) * (tab_len(info) + 1));
	if (sprites == NULL)
		return (NULL);
	for (; info[i] != NULL; i++) {
		if (!create_sprite(&sprites[i], texture_bank, info, i))
			return (NULL);
	}
	sprites[i] = NULL;
	free_2d_arr(info);
	return (sprites);
}
