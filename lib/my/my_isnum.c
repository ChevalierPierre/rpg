/*
** EPITECH PROJECT, 2018
** my_isnum
** File description:
** check nbr on a string
*/

#include <stdlib.h>

int my_char_isnum(char c)
{
	if (c > '9' || c < '0')
		return (0);
	return (1);
}

int my_isnum(char *str)
{
	if (str == NULL)
		return (0);
	for (int i = 0; str[i]; i++)
		if (str[i] > '9' || str[i] < '0')
			return (0);
	return (1);
}
