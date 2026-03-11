#include <stdio.h>

/**
 * main - prints the number of arguments passed to the program
 * @argc: number of arguments
 * @argv: array of arguments (unused)
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argv; /* unused parameter */
	printf("%d\n", argc - 1);
	return (0);
}
