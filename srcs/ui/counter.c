/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu
*/

#include <time.h>
#include "rpg.h"

int counter(sfClock *clock)
{
	sfTime time;
	float seconds;
	static int counter = 1;

	time = sfClock_getElapsedTime(clock);
	seconds = time.microseconds / 1000000.0;
	if (seconds > 0.000001) {
		counter++;
		sfClock_restart(clock);
	}
	if (counter > 1000)
		counter = 0;
	return counter;
}
