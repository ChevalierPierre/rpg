/*
** EPITECH PROJECT, 2018
** tab_len
** File description:
** get the length of a char **
*/

#include <stdlib.h>

int tab_len(char **tab)
{
	int i = 0;

	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}
