/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** get the size of a string.
*/

int my_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0') {
		i += 1;
	}
	return (i);
}
