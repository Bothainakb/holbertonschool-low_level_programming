#include "main.h"
#include <unistd.h>

/**
 * rev_string - prints a string in reverse, followed by a new line
 * @s: pointer to the string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length;

	length = 0;
	while (s[length] != '\0')
		length++;

	while (length > 0)
	{
		length--;
		write(1, &s[length], 1);
	}

	write(1, "\n", 1);
}
