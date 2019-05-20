/*
** EPITECH PROJECT, 2018
** array size
** File description:
** get size of an array
*/

#include <stdlib.h>

int array_size(char **arr)
{
	int i = 0;

	for (; arr[i] != NULL; i++);
	return (i);
}
