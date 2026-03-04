#include <stdio.h>

/**
 * puts2 - prints every other character of a string
 * @str: the string to print
 *
 * Description: Starts with the first character and prints
 * every second character followed by a new line.
 */
void puts2(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (i % 2 == 0)
            putchar(str[i]);
        i++;
    }
    putchar('\n');
}
