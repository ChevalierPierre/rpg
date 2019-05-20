/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** concatenate two strings
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
	int n = my_strlen(dest);
	int i = 0;

	while (src[i] != '\0') {
		dest[n] = src[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	return (dest);
}
