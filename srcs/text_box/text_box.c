/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** text_box
*/

#include "rpg.h"

static int display_content(sfSprite *bck, sfText *font, char **txt, rpg_t *rpg)
{
	static int i = 0;
	sfVector2f ref = {625, 640};
	sfVector2f pos = ref;
	int status = 0;

	sfRenderWindow_drawSprite(rpg->window.window, bck, NULL);
	sfRenderWindow_drawSprite(rpg->window.window,
				rpg->utils_sprite[20], NULL);
	for (; txt[i] != NULL && txt[i][0] != '\0'; i++, pos.x = ref.x) {
		sfText_setString(font, txt[i]);
		sfText_setPosition(font, pos);
		sfRenderWindow_drawText(rpg->window.window, font, NULL);
		pos.y += 40;
	} if (txt[i] == NULL) {
		i = -1;
		status = 1;
	}
	i++;
	wait(300);
	return (status);
}

static sfImage *take_screenshot(rpg_t *rpg)
{
	sfImage *bck = NULL;

	sfRenderWindow_display(rpg->window.window);
	bck = sfRenderWindow_capture(rpg->window.window);
	return (bck);
}

static void destroy_components(sfImage *im, sfSprite *sp, sfTexture *text,
			sfText *font)
{
	sfImage_destroy(im);
	sfSprite_destroy(sp);
	sfTexture_destroy(text);
	sfText_destroy(font);
}

void write_text(char *path, rpg_t *rpg)
{
	sfImage *bck = take_screenshot(rpg);
	sfTexture *text = NULL;
	sfSprite *sprite = sfSprite_create();
	sfText *font = init_text(35, "assets/font/rpg.otf",
				(sfVector2f){625, 640}, sfWhite);
	char **txt = read_file(path);
	int status = 0;

	if (!create_background(&sprite, &text, bck) || !font || !txt)
		return;
	while (sfRenderWindow_isOpen(rpg->window.window) && status != 1) {
		test_close(rpg->window.window);
		status = display_content(sprite, font, txt, rpg);
		sfRenderWindow_display(rpg->window.window);
		while (!sfKeyboard_isKeyPressed(sfKeySpace) &&
		sfRenderWindow_isOpen(rpg->window.window))
			test_close(rpg->window.window);
		sfMusic_play(rpg->soundbox[13]);
	}
	destroy_components(bck, sprite, text, font);
}
