/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** unit tests rpg
*/

#include <criterion/criterion.h>
#include "rpg.h"
#include "my.h"

Test(rpg, test_1)
{
	char **txt = read_file("../config/text/end.text");
	char *ref[13] = {"Something shine among dead bodies ...",
			"", "You find The Light Stone !",
			"", "You hear a voice ...",
			"", "Young Hero ...", "",
			"You save the world !", "",
			"Thank you ...", "", "..." };

	for (int i = 0; txt[i] != NULL; i++)
		cr_assert_eq(my_strcmp(txt[i], ref[i]), 0, "FAIL");
	free_2d_arr(txt);
}
