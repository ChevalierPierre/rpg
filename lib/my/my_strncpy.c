/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** copy n character into a string
*/

char *my_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n) {
		dest[i] = src[i];
		i = i + 1;
		if (src[i] == '\0')
			break;
	}
	dest[i] = '\0';
	return (dest);
}
