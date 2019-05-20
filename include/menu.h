/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** header file for rpg project
*/

#ifndef MENU_H
#define MENU_H

#include "struct.h"

/*DESTROY*/
void destroy_menu(sfRenderWindow *window, menu_t *menu);
void destroy_pause(pause_t *pause);

/*DRAW*/
void draw_menu(sfRenderWindow *window, menu_t *menu);
void draw_option(sfRenderWindow *window, option_t *option);
void draw_pause(sfRenderWindow *window, pause_t *pause);
void display_pause(pause_t *pause);

/* INIT */
void init_pause_button(pause_t *pause);
pause_t *init_pause_menu(void);
sprite_t *init_sprite(sprite_t *sprite, char *path, sfVector2f pos
	, sfIntRect rect);
sprite_t *init_sprite_color(sprite_t *sprite, sfColor color);
option_t *init_option(option_t *option);
link_t *init_cloud(void);
void clouds_gestion(menu_t *menu);
int add_cloud(link_t *link);
window_t init_window(void);
menu_t *init_main_menu(void);
background_t *load_background(char *path);

/* UTILS */
int counter(sfClock *clock);

/*OPTION*/
void init_fullscreen(option_t *option);

/*MENU*/
int menu_navigation(window_t window, sprite_t *button);
int manage_button(window_t window, menu_t *menu);
void change_volume(window_t window, menu_t *menu);
void set_fullscreen(menu_t *menu, option_t *option, window_t window);

/*TRANSITION*/
void starting_press(menu_t *menu);
void start_option(menu_t *menu);

/*EFFECTS*/
void smooth_get_color(sprite_t *sprite);
void smooth_transparent(sprite_t *sprite, int speed);
void smooth_blink(sfSprite *sprite);

/*SCENES_LOOP*/
int pause_loop(rpg_t *);
int menu_loop(rpg_t *);

#endif
