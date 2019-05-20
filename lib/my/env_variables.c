/*
** EPITECH PROJECT, 2018
** minihsell
** File description:
** get an environement viariable
*/

#include <stdlib.h>

int my_strlen(char *);

char *get_env_variable(char **env, char *v_name)
{
	int i = 0;
	int x = 0;
	int y = 0;
	char *content;

	for ( ; v_name[i] != '\0'; i++) {
		if (v_name[i] != env[y][x]) {
			y++;
			x = 0;
			i = -1;
		} else
			x++;
	}
	content = &env[y][my_strlen(v_name) + 1];
	return (content);
}
