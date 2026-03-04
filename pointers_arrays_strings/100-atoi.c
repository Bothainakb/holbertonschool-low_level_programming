#include <stdlib.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the integer value represented by the string
 */
int _atoi(char *s)
{
	int i, sign;
	unsigned int num;

	i = 0;
	sign = 1;
	num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			break;
		}
		i++;
	}

	if (sign == -1 && num > 2147483648)
		return (-2147483648);
	if (sign == 1 && num > 2147483647)
		return (2147483647);

	if (sign == -1)
		return (-((int)num));
	return ((int)num);
}
