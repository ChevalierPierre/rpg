/*
** EPITECH PROJECT, 2018
** free_2d_arr
** File description:
** free a 2d array
*/

#include <stdlib.h>

void free_2d_arr(char **arr)
{
	for(int i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}
