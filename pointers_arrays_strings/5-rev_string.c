#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 *
 * Description: Modifies the string in place.
 */
void rev_string(char *s)
{
	int i, len;
	char temp;

	len = 0;
	while (s[len] != '\0')
		len++;

	i = 0;
	while (i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
		i++;
	}
}
