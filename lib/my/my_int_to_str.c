/*
** EPITECH PROJECT, 2017
** my_int_to_str
** File description:
** convert int into a string.
*/

#include <stdlib.h>

char *my_strdup(char *);
char *my_revstr(char *);

int count_int_digit(int n)
{
	int res = n;
	int i = 0;

	if (n < 0)
		n = n * -1;
	while (res != 0) {
		res = res / 10;
		i++;
	}
	return (i);
}

char *my_int_to_str(int nb)
{
	char *res = malloc(sizeof (char) * (count_int_digit(nb) + 2));
	int end = nb;
	int i = 0;

	if (res == NULL)
		return (NULL);
	if (nb == 0)
		return (my_strdup("0"));
	else if (end < 0)
		  end = end * -1;
	while (end != 0) {
		res[i] = (end % 10) + 48;
		end = end / 10;
		i++;
	} if (nb < 0) {
		res[i] = '-';
		i++;
	}
	res[i] = '\0';
	return (my_revstr(res));
}
