/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** split a string to a double array
*/

#include <stdlib.h>

int count_words(char *str)
{
	int count = 0;
	int i = 0;

	for ( ; str[i] == ' '; i++);
	for ( ; str[i] != '\0'; i++) {
		if (str[i] == ' ' && str[i + 1] != ' ')
			count++;
	}
	if (str[i - 1] != ' ')
		count++;
	return (count);
}

int get_word_len(char *str, int i)
{
	int count = 0;

	for (; str[i] != ' ' && str[i] != '\0'; i++) {
		count++;
	}
	return (count);
}

char *copy_word(char *str, char *word, int *cursor)
{
	int n = 0;

	while (str[*cursor] == ' ')
		*cursor += 1;
	for ( ; str[*cursor] != ' ' && str[*cursor] != '\0'; n++) {
		word[n] = str[*cursor];
		*cursor += 1;
	}
	word[n] = '\0';
	while (str[*cursor] == ' ')
		*cursor += 1;
	return (word);
}

char **my_str_to_word_array(char *str)
{
	int words = count_words(str);
	char **res = malloc(sizeof(char *) * (words + 1));
	int i = 0;
	int cursor = 0;

	if (res == NULL)
		return (NULL);
	for ( ; i < words; i++) {
		res[i] = malloc(sizeof(char) * (get_word_len(str, cursor) + 1));
		if (res[i] == NULL)
			return (NULL);
		res[i] = copy_word(str, res[i], &cursor);
	}
	res[i] = NULL;
	return (res);
}
