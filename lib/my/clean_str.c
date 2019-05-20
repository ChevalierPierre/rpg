/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** clean space and tab on a string
*/

#include <stdlib.h>

int my_strlen(char *);

char *clean_str(char *str)
{
	int i = 0;
	int n = 0;
	char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

	for (; str[i] == ' ' || str[i] == '\t'; i++);
	while (str[i] != '\0') {
		if (str[i] != ' ' && str[i] != '\t') {
			res[n] = str[i];
			n++;
		} else if (str[i + 1] != '\0' && str[i + 1]
			!= ' ' && str[i + 1] != '\t') {
			res[n] = ' ';
			n++;
		}
		i++;
	}
	res[n] = '\0';
	free(str);
	return (res);
}
