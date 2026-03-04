#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the integer value represented by the string
 */
int _atoi(char *s)
{
	int i, sign, started;
	unsigned int num;

	i = 0;
	sign = 1;
	num = 0;
	started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && !started)
			sign *= -1;
		else if (s[i] == '+' && !started)
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (started)
			break;
		i++;
	}

	/* Avoid negating INT_MIN by casting to int after unsigned accumulation */
	if (sign == -1)
		return (0 - (int)num);
	return ((int)num);
}
