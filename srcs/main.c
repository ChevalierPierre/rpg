/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main function
*/

#include "rpg.h"
#include "menu.h"

int main(int ac, char **av, char **env)
{
	rpg_t *rpg;

	(void)ac;
	(void)av;
	if (env[0] == NULL)
		return (84);
	rpg = init_game_struct();
	if (rpg == NULL)
		return (84);
	my_rpg(rpg);
	return (0);
}
