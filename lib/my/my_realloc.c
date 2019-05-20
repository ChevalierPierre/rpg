/*
** EPITECH PROJECT, 2017
** my_realloc.c
** File description:
** realloc an array.
*/

#include <stdlib.h>

int my_strlen(char *);
char *my_strcpy(char *, char *);

char *my_realloc(char *str, int i)
{
	char *res;

	if (str == NULL)
		res = malloc(sizeof (char) * i);
	else {
		res = malloc(sizeof (char) * (my_strlen(str) + i));
		res = my_strcpy(res, str);
		free(str);
	}
	return (res);
}
