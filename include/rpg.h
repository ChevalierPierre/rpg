/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** header file for rpg project
*/

#ifndef RPG_H
#define RPG_H

#include "struct.h"

void my_rpg(rpg_t *);

/* ENTITY */
entity_t *get_entity(int, int, char **, room_t *);
linked_list_t *get_room_entity(char **, room_t *);
sfSprite *load_door_sprite(sfTexture **);
void free_entity(linked_list_t *);
void free_all_mob(linked_list_t *);

/* INIT */
rpg_t *init_game_struct(void);
sfTexture **load_texture(void);
character_t *init_player(sfTexture **);

/* UTILS */
sfVector2f convert_pos(sfVector2f, float);
sfIntRect create_rect(int, int, int, int);
void test_close(sfRenderWindow *);
char **read_file(char *);
void wait(int);
void free_rpg_struct(rpg_t *);
sfText *init_text(int, char *, sfVector2f, sfColor);
sfSprite **create_utils_sprite(sfTexture **);
int create_background(sfSprite **, sfTexture **, sfImage *);

/* ROOMS */
room_t *load_room(char *, sfTexture **);
void disp_room(room_t *, rpg_t *);
room_t *get_room_by_name(char *name, linked_list_t *);
room_t *get_room_by_nbr(room_t *, int);
int exit_tavern(room_t *, rpg_t *);
void process_tavern(rpg_t *, int);
int boss(rpg_t *);
void set_sprite(sfSprite *, sfVector2f, sfVector2f);
void free_mem(char *, char **);

/* CHARACTERS */
void move_character(anim_t, int, room_t *, linked_list_t *);
void display_static_character(sfRenderWindow *, character_t *);
void character_attack(sfRenderWindow *, character_t *);

/* COLLISIONS */
int check_collision(room_t *, character_t *, linked_list_t *);
int test_collision(sfVector2f *, sfVector2f *);
int check_characters_collision(character_t *, character_t *, rpg_t *);

/* HITBOX */
sfVector2f *get_attack_hitbox(character_t *);
sfVector2f *get_character_hitbox(character_t *);

/* DUNGEON */
room_t *load_dungeon(char *, sfTexture **, linked_list_t **);
int run_dungeon(rpg_t *);
room_t *switch_room(room_t *, rpg_t *, linked_list_t **);

/* MOBS */
void process_mob(linked_list_t **, rpg_t *, room_t *);
int load_room_mob(room_t *, linked_list_t **, rpg_t *);
void destroy_mob(character_t *);
void mob_attack(character_t *, character_t *, sfMusic **);
void mob_hurt(character_t *);
void set_new_mob_pos(linked_list_t *, sfVector2f);
void set_mob_attributes(character_t *);

/* PLAYER */
void move_player(rpg_t *, room_t *);
void player_attack(character_t *, linked_list_t *, rpg_t *);
int process_player(rpg_t *, room_t *, linked_list_t *);
void trigger_button(character_t *, room_t *, sfMusic **);
void set_player_pos(room_t *, character_t *);
void ultimate_attack(rpg_t *, linked_list_t *);
void move_player(rpg_t *, room_t *);

/* HUD */
void display_inventory(rpg_t *);
void draw_hud(rpg_t *);
int draw_map(rpg_t *);
void shop(rpg_t *);
int game_over(rpg_t *);
int end_menu(rpg_t *);

/* EVENT */
void display_event(rpg_t *);
void mob_death(rpg_t *, character_t *);
void destroy_event(event_t *);
sfMusic **load_music(void);
int on_shop(room_t *, rpg_t *);
void write_text(char *, rpg_t *);
int interact_button(rpg_t *, sfVector2f *, sfVector2f *);

/* PARTICLES */
void display_particles(rpg_t *, sfVector2f);

#endif
