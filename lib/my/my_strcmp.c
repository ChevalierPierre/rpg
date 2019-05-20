/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** compair two strings
*/

int my_strcmp(char const *str, char const *str2)
{
	int i = 0;
	int rtn_value;

	while (str[i] != '\0') {
		if (str[i] == str2[i]) {
			i += 1;
		} else
			break;
	}
	if (str[i] == '\0' && str2[i] == '\0')
		return (0);
	rtn_value = str[i] - str2[i];
	return (rtn_value);
}
