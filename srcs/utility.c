/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** utility csfml functions
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "rpg.h"
#include "my.h"

char **read_file(char *path)
{
	int fd = open(path, O_RDONLY);
	char *line;
	char **map = NULL;

	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	for (int i = 0; line != NULL; i++, line = get_next_line(fd)) {
		map = tab_realloc(map, 1);
		if (map == NULL)
			return (NULL);
		map[i] = line;
	}
	return (map);
}

void test_close(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event))
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);

}

sfIntRect create_rect(int width, int height, int left, int top)
{
	sfIntRect rect;

	rect.width = width;
	rect.height = height;
	rect.left = left;
	rect.top = top;
	return (rect);
}

void wait(int time)
{
	sfClock *clock = sfClock_create();

	while (1) {
		if (sfTime_asMilliseconds(sfClock_getElapsedTime
					(clock)) >= time)
			break;
	}
	sfClock_destroy(clock);
}

sfText *init_text(int size, char *font_path, sfVector2f pos, sfColor color)
{
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile(font_path);

	if (text == NULL || font == NULL)
		return (NULL);
	sfText_setColor(text, color);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setFont(text, font);
	return (text);
}
