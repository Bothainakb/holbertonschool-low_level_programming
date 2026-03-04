#include <unistd.h>
#include <stdlib.h>

/**
 * puts_half - prints the second half of a string
 * @str: the string to print
 *
 * Description: If the length is odd, prints the last
 * (length + 1) / 2 characters. Uses write only.
 */
void puts_half(char *str)
{
	int len, start, i;

	len = 0;
	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	i = start;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
