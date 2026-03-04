#include "main.h"
#include <unistd.h>

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string to be printed
 *
 * Return: void
 */
void print_rev(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
		i++;

	while (i > 0)
	{
		i--;
		write(1, &s[i], 1);
	}

	write(1, "\n", 1);
}
