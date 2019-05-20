/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** rpg
*/

#include "rpg.h"

void do_evnext(global_t *glob)
{
        glob->souris.x = glob->event.mouseButton.x;
        glob->souris.y = glob->event.mouseButton.y;
        glob->play_button->r->left =
                sfSprite_getPosition(glob->play_button->btn).x;
        glob->play_button->r->top =
                sfSprite_getPosition(glob->play_button->btn).y;
        glob->play_button->r->width = glob->play_button->r_.width;
        glob->play_button->r->height = glob->play_button->r_.height;
        glob->echap_button->r->left =
                sfSprite_getPosition(glob->echap_button->btn).x;
        glob->echap_button->r->top =
                sfSprite_getPosition(glob->echap_button->btn).y;
        glob->echap_button->r->width = glob->echap_button->r_.width;
        glob->echap_button->r->height = glob->echap_button->r_.height;
}

void do_events(global_t *glob)
{
        do_evnext(glob);
        if (glob->nnew == 0) {
                if (sfFloatRect_contains
                    (glob->play_button->r, glob->souris.x, glob->souris.y) == 1)
                        glob->nnew = 1;
                if (sfFloatRect_contains
                    (glob->echap_button->r, glob->souris.x, glob->souris.y) == 1)
                        sfRenderWindow_close(glob->window);
        }
}

void event(global_t *glob)
{
        if (glob->event.type == sfEvtClosed ||
            (glob->event.type == sfEvtKeyPressed &&
             glob->event.key.code == sfKeyEscape))
                sfRenderWindow_close(glob->window);
        if (glob->event.type == sfEvtMouseButtonPressed)
                do_events(glob);
}
