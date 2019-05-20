/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** return 0 if there is only alphanum character
*/

int my_str_isalpha(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] >= 65 && str[i] <= 90) ||
		(str[i] >= 97 && str[i] <= 122) ||
		(str[i] >= 48 && str[i] <= 57) || str[i] == '_')
			i += 1;
		else
			return (1);
	}
	return (0);
}
