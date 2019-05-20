/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** display a charactere
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
