/*
** EPITECH PROJECT, 2018
** power
** File description:
** compute power
*/

int power(int nb, int p)
{
	int res;

	if (p == 0)
		return (1);
	else if (p < 0)
		return (0);
	else {
		res = nb * power(nb, (p - 1));
		return (res);
	}
}
