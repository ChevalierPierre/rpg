/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** initialisation functions
*/

#include "rpg.h"
#include "menu.h"

link_t *init_cloud(void)
{
	link_t *link = malloc(sizeof(link_t));
	cloud_t *first = malloc(sizeof(cloud_t));

	first->cloud.texture = sfTexture_createFromFile(
		"assets/ui/sprites/Backgrounds/cloud.png", NULL);
	first->cloud.sprite = sfSprite_create();
	first->cloud.position.x = 1500;
	first->cloud.position.y = 400;
	first->next = NULL;
	first->back = NULL;
	link->begin = first;
	link->end = first;
	sfSprite_setTexture(first->cloud.sprite, first->cloud.texture, sfTrue);
	sfSprite_setPosition(first->cloud.sprite, first->cloud.position);
	return link;
}

int add_cloud(link_t *link)
{
	cloud_t *node = malloc(sizeof(cloud_t));

	node->cloud.texture = sfTexture_createFromFile(
		"assets/ui/sprites/Backgrounds/cloud.png", NULL);
	node->cloud.sprite = sfSprite_create();
	node->next = NULL;
	node->back = link->end;
	link->end->next = node;
	link->end = node;
	sfSprite_setTexture(node->cloud.sprite, node->cloud.texture, sfTrue);
	sfSprite_setPosition(node->cloud.sprite,
			(sfVector2f){2000, rand() % 900});
	return 0;
}

void clouds_gestion(menu_t *menu)
{
	for (cloud_t *now = menu->link.begin; now != NULL; now = now->next)
		sfSprite_move(now->cloud.sprite, (sfVector2f){-1, 0});
	if (counter(menu->clock) == 1000)
		add_cloud(&menu->link);
}
