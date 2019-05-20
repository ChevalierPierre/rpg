/*
** EPITECH PROJECT, 2018
** my_put_tab
** File description:
** display a char **
*/

#include <unistd.h>

int my_strlen(char *);

void my_put_tab(char **tab)
{
	for (int i = 0; tab[i] != NULL; i++) {
		write(1, tab[i], my_strlen(tab[i]));
		write(1, "\n", 1);
	}
}
