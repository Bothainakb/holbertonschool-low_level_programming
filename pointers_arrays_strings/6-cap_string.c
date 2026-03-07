#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 'a' && s[i] <= 'z') &&
		    (i == 0 ||
		     s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n' ||
		     s[i - 1] == ',' || s[i - 1] == ';' || s[i - 1] == '.' ||
		     s[i - 1] == '!' || s[i - 1] == '?' || s[i - 1] == '"' ||
		     s[i - 1] == '(' || s[i - 1] == ')' || s[i - 1] == '{' ||
		     s[i - 1] == '}'))
			s[i] = s[i] - ('a' - 'A');
		i++;
	}

	return (s);
}
