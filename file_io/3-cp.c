#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int open_files(int *fd_from, int *fd_to, char **av);
void close_fds(int fd_from, int fd_to, char *buffer);

/**
 * main - copies file_from to file_to
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char *buffer;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		exit(99);

	if (open_files(&fd_from, &fd_to, av) == -1)
	{
		free(buffer);
		exit(98);
	}

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close_fds(fd_from, fd_to, buffer);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close_fds(fd_from, fd_to, buffer);
		exit(98);
	}

	close_fds(fd_from, fd_to, buffer);
	return (0);
}

/**
 * open_files - opens source and destination files
 * @fd_from: pointer to source fd
 * @fd_to: pointer to destination fd
 * @av: arguments
 *
 * Return: 0 on success, -1 on failure
 */
int open_files(int *fd_from, int *fd_to, char **av)
{
	*fd_from = open(av[1], O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		return (-1);
	}

	*fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close(*fd_from);
		return (-1);
	}

	return (0);
}

/**
 * close_fds - closes files and frees buffer
 * @fd_from: source fd
 * @fd_to: destination fd
 * @buffer: allocated buffer
 */
void close_fds(int fd_from, int fd_to, char *buffer)
{
	int c;

	free(buffer);

	c = close(fd_from);
	if (c == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);

	c = close(fd_to);
	if (c == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
} 
