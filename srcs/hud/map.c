/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** interactive map
*/

#include "rpg.h"

static void interact_map(rpg_t *rpg, sfSprite *bck, int *tmp)
{
	sfIntRect rect = create_rect(840, 693, 0, 0);

	test_close(rpg->window.window);
	sfRenderWindow_drawSprite(rpg->window.window, bck, NULL);
	if (*tmp == 0 && sfKeyboard_isKeyPressed(sfKeyUp))
		*tmp = 1;
	if ((*tmp == 1 || *tmp == 2) && sfKeyboard_isKeyPressed(sfKeyDown)) {
		*tmp -= 1;
		wait(300);
	} if (*tmp == 3 && sfKeyboard_isKeyPressed(sfKeyDown))
		*tmp = 1;
	if (*tmp == 1 && sfKeyboard_isKeyPressed(sfKeyLeft))
		*tmp = 2;
	if (*tmp == 1 && sfKeyboard_isKeyPressed(sfKeyRight))
		*tmp = 3;
	rect.left = rect.width * (*tmp);
	sfSprite_setTextureRect(rpg->utils_sprite[15], rect);
	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[15], NULL);
	sfRenderWindow_display(rpg->window.window);
}

static void destroy_component(sfSprite *sprite, sfImage *bck, sfTexture *text)
{
	sfImage_destroy(bck);
	sfTexture_destroy(text);
	sfSprite_destroy(sprite);
}

int create_background(sfSprite **sp, sfTexture **text, sfImage *im)
{
	if (im == NULL || *sp == NULL)
		return (0);
	*text = sfTexture_createFromImage(im, NULL);
	sfSprite_setTexture(*sp, *text, sfTrue);
	if (*sp == NULL || *text == NULL)
		return (0);
	return (1);
}

int draw_map(rpg_t *rpg)
{
	sfImage *bck = sfRenderWindow_capture(rpg->window.window);
	sfTexture *text = NULL;
	sfSprite *sprite = sfSprite_create();
	int tmp = rpg->location;

	if (!create_background(&sprite, &text, bck))
		return (-1);
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			break;
		interact_map(rpg, sprite, &tmp);
		if (tmp != 1 && tmp != rpg->location &&
		sfKeyboard_isKeyPressed(sfKeySpace)) {
			rpg->location = tmp;
			return (42);
		}
	}
	destroy_component(sprite, bck, text);
	return (-1);
}
