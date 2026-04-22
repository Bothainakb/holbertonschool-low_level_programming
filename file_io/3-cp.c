#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void copy_file(int fd_from, int fd_to, char *file_from, char *file_to);
void close_fd(int fd, char *buffer, int is_from);

/**
 * main - entry point
 * @ac: argument count
 * @av: arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	char *buffer;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO,
			"Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		exit(99);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", av[1]);
		free(buffer);
		exit(98);
	}

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", av[2]);
		free(buffer);
		close(fd_from);
		exit(99);
	}

	copy_file(fd_from, fd_to, av[1], av[2]);

	free(buffer);
	close_fd(fd_from, NULL, 0);
	close_fd(fd_to, NULL, 0);

	return (0);
}

/**
 * copy_file - copies data
 */
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t r, w;

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * close_fd - closes file descriptor safely
 */
void close_fd(int fd, char *buffer, int is_from)
{
	int c;

	c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(100);
	}

	if (buffer && is_from)
		free(buffer);
}
