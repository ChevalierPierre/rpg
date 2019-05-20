/*
** EPITECH PROJECT, 2018
** find_char
** File description:
** find a char in a string
*/

int find_char(char *str, char c)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return (1);
	return (0);
}
