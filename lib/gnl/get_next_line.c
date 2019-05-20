/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** read a file line by line
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char *my_realloc(char *str, int i)
{
	char *res;
	int strlen;
	int c;

	if (str == NULL) {
		res = malloc(sizeof (char) * (i + 1));
		if (res == NULL)
			return (NULL);
	} else {
		for (strlen = 0; str[strlen] != '\0'; strlen++);
		res = malloc(sizeof (char) * (strlen + i + 1));
		if (res == NULL)
			return (NULL);
		for (c = 0; str[c] != '\0'; c++)
			res[c] = str[c];
		res[c] = '\0';
		free(str);
	}
	return (res);
}

char *copy(char buffer, int *n, char *stack)
{
	if (buffer == '\n' || *n != 0) {
		stack = my_realloc(stack, 2);
		if (stack == NULL)
			return (NULL);
		stack[*n] = buffer;
		*n += 1;
		stack[*n] = '\0';
	}
	return (stack);
}

char *parse_and_copy(char *buffer, char *line, char *stack, int byte_read)
{
	int len = 0;
	int n = 0;

	buffer[byte_read] = '\0';
	for ( ; line[len] != '\0'; len++);
	for (int i = 0; buffer[i] != '\0'; i++, len++) {
		stack = copy(buffer[i], &n, stack);
		if (n == 0 && buffer[i] != '\n')
			line[len] = buffer[i];
	}
	line[len] = '\0';
	if (n != 0) {
		stack[n] = '\0';
		stack = &stack[1];
	}
	return (stack);
}

char *concat_stack(char **line, char *stack)
{
	int n = 0;
	int i = 0;

	(*line)[0] = '\0';
	if (stack == NULL)
		return (NULL);
	*line = my_realloc(*line, READ_SIZE);
	for ( ; stack[i] != '\0' && stack[i] != '\n'; n++, i++)
		(*line)[n] = stack[i];
	(*line)[n] = '\0';
	if (stack[i] != '\0')
		stack = &stack[n + 1];
	else
		return (NULL);
	return (stack);
}

char *get_next_line(int fd)
{
	static char *stack = NULL;
	char *line = malloc(sizeof(char));
	char buf[READ_SIZE + 1];
	int br;

	if (line == NULL)
		return (NULL);
	stack = concat_stack(&line, stack);
	if (stack == NULL)
		br = read(fd, buf, READ_SIZE);
	while (stack == NULL && br != 0) {
		if (br == -1)
			return (NULL);
		line = my_realloc(line, br + 1);
		stack = parse_and_copy(buf, line, stack, br);
		if (stack == NULL)
			br = read(fd, buf, READ_SIZE);
	} if ((line[0] == '\0' && stack == NULL && br == 0) || line == NULL)
		return (NULL);
	return (line);
}
