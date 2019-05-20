/*
** EPITECH PROJECT, 2018
** tab_realloc
** File description:
** realloc a 2d arr
*/

#include <stdlib.h>

char *my_strdup(char *);
int tab_len(char **);

char **tab_realloc(char **tab, int n)
{
	char **new_tab = malloc(sizeof(char *) * (tab_len(tab) + n + 1));
	int i = 0;

	if (new_tab == NULL)
		return (NULL);
	new_tab[tab_len(tab) + n] = NULL;
	if (tab == NULL)
		return (new_tab);
	for (i = 0; tab[i] != NULL; i++)
		new_tab[i] = my_strdup(tab[i]);
	free(tab);
	return (new_tab);
}
