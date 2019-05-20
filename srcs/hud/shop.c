/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** shop
*/

#include "my.h"
#include "rpg.h"

static void destroy_components(sfSprite *sprite, sfImage *bck, sfTexture *text,
			sfText *txt)
{
	sfImage_destroy(bck);
	sfTexture_destroy(text);
	sfSprite_destroy(sprite);
	sfText_destroy(txt);
}

static void manage_window(rpg_t *rpg)
{
	sfVector2i mouse = sfMouse_getPosition((sfWindow *) rpg->window.window);
	int a = 0;

	if (mouse.x > 462 && mouse.x < 716 && mouse.y > 345 && mouse.y < 785) {
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[18], NULL);
		a = 1;
	} else
		sfRenderWindow_drawSprite(rpg->window.window,
					rpg->utils_sprite[17], NULL);
	if (a == 1 && rpg->player->gold >= 10 && rpg->player->potions < 4 &&
	sfMouse_isButtonPressed(sfMouseLeft)) {
		rpg->player->potions++;
		rpg->player->gold -= 10;
		sfMusic_play(rpg->soundbox[1]);
		wait(300);
	}
}

void shop(rpg_t *rpg)
{
	sfText *txt = txt = init_text(70, "assets/font/rpg.otf",
				(sfVector2f){530, 235},
				(sfColor){255, 173, 43, 255});
	sfImage *bck = sfRenderWindow_capture(rpg->window.window);
	sfTexture *text = NULL;
	sfSprite *sprite = sfSprite_create();

	if (!create_background(&sprite, &text, bck) || txt == NULL)
		return;
	while (sfRenderWindow_isOpen(rpg->window.window)) {
		test_close(rpg->window.window);
		sfRenderWindow_drawSprite(rpg->window.window, sprite, NULL);
		manage_window(rpg);
		sfText_setString(txt, my_int_to_str(rpg->player->gold));
		sfRenderWindow_drawText(rpg->window.window, txt, NULL);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			break;
		sfRenderWindow_display(rpg->window.window);
	}
	destroy_components(sprite, bck, text, txt);
}
