/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** convert a string to an int
*/

void integer_detector(int *res, long long integer,
		int digit_count, char *digits)
{
	int i = digit_count - 1;

	if (integer < 0)
		integer = integer * (-1);
	if ((integer % 10) != (digits[i] - 48))
		*res = 0;
}

char *find_digit(char *str)
{
	int i = 0;
	char *ptr;

	while (str[i] != '\0') {
		if (str[i] >= 48 && str[i] <= 57) {
			ptr = &str[i];
			return (ptr);
		}
		else if (str[i] == 45 && str[i + 1] >= 48 && str[i + 1] <= 57) {
			ptr = &str[i];
			return (ptr);
		}
		i += 1;
	}
	return (0);
}

int power(int nb, int p)
{
	int res;

	if (p == 0)
		return (1);
	else if (p < 0)
		return (0);
	else
	{
		res = nb * power(nb, (p - 1));
		return (res);
	}
}

int count_digits(char *str)
{
	int i = 0;
	int count = 0;

	if (str[i] == '-')
		i += 1;
	while (1) {
		if (str[i] >= 48 && str[i] <= 57)
			count += 1;
		else
			break;
		i += 1;
	}
	return (count);
}

int my_getnbr(char *str)
{
	char *digit = find_digit(str);
	int i = 0;
	int res = 0;
	int digits_count = count_digits(digit);
	int x = power(10, digits_count - 1);

	if (digit[0] == '-') {
		i += 1;
		digits_count += 1;
	}
	while (i <  digits_count) {
		res = res + ((digit[i] - 48) * x);
		x = x / 10;
		i = i + 1;
	}
	integer_detector(&res, res, digits_count, digit);
	if (digit[0] == '-')
		res = res * (-1);
	return (res);
}
