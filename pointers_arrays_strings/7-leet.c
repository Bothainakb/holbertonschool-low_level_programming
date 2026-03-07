#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	int i, j;
	char l[] = "aAeEoOtTlL";
	char n[] = "4433007711";

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (j < 10)
		{
			if (s[i] == l[j])
				s[i] = n[j];
			j++;
		}
		i++;
	}

	return (s);
}
