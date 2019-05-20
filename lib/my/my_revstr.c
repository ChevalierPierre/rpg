/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse characters of a string
*/

char *my_strdup(char *);
int my_strlen(char *);

char *my_revstr(char *str)
{
	int i = 0;
	int n;
	char *cpy;

	n = my_strlen(str);
	cpy = my_strdup(str);
	while (str[i] != '\0') {
		str[i] = cpy[n - 1];
		i += 1;
		n -= 1;
	}
	return (str);
}
