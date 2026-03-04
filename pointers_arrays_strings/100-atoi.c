#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value represented by the first number found
 */
int _atoi(char *s)
{
	int i, sign, num, digit_found;

	i = 0;
	sign = 1;
	num = 0;
	digit_found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && !digit_found)
			sign *= -1;
		else if (s[i] == '+' && !digit_found)
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit_found = 1;
			if (sign == -1)
				num = num * 10 - (s[i] - '0');
			else
				num = num * 10 + (s[i] - '0');
		}
		else if (digit_found)
			break;
		i++;
	}

	return (num);
}
