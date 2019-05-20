/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** copy and aloocate a string
*/

#include <stdlib.h>

int my_strlen(char const *);

char *my_strdup(char const *src)
{
	int destlen;
	int i = 0;
	char *dest;

	destlen = my_strlen(src);
	dest = malloc(sizeof(char) * (destlen + 1));
	if (dest == NULL)
		return (NULL);
	while (i < destlen) {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}
