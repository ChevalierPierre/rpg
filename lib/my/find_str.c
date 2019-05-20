/*
** EPITECH PROJECT, 2018
** find str
** File description:
** find a string into a string
*/

int find_str(char *str, char *to_find)
{
	int n = 0;

	for (int i = 0; str[i] != '\0' && to_find[n] != '\0'; i++) {
		if (str[i] == to_find[n])
			n++;
		else
			n = 0;
	}
	if (to_find[n] == '\0')
		return (1);
	return (0);
}
