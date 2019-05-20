/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** split a string to a double dimension array
*/

#include <stdlib.h>

int count_words2(char *str, char c)
{
	int n = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			n++;
	}
	return (n + 1);
}

char *get_word(char *map, int *i, char *str, char c)
{
	int n = 0;

	while (map[*i] != c && map[*i] != '\0') {
		str[n] = map[*i];
		*i += 1;
		n++;
	}
	str[n] = '\0';
	return (str);
}

int line_len(char *str, char c)
{
	static int i = 0;
	int len = 0;

	for (; str[i] != c && str[i] != '\0'; i++)
		len++;
	if (str[i] == '\0')
		i = -1;
	i++;
	return (len);
}

char **split_by(char *str, char c)
{
	int words = count_words2(str, c);
	char **res = malloc(sizeof(char *) * (words + 1));
	int n = 0;
	int i = 0;

	for ( ; i < words; i++, n++) {
		res[i] = malloc(sizeof(char) * (line_len(str, c) + 1));
		res[i] = get_word(str, &n, res[i], c);
	}
	res[i] = NULL;
	return (res);
}
