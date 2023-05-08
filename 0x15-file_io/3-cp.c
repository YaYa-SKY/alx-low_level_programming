#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024
/**
 * create_buff - the allocates 1024 bytes for buffer.
 * @file: name specifier of the file buff  chars for.
 * Return: pointer to the newly-allocated buffer.
 */
char *create_buff(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);

}
/**
 * cloose_file - the close file descriptors.
 * @fd: The file descriptor to be closed.
 */
void cloose_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - copies the contents specifier of a file.
 * @argc: The number of argument supplied program.
 * @argv: array of pointers to the arguments.
 * Return: 0 on success.
 * Description: if the argument specifier - exit code 97.
 * if file_from does not exist be read - exit code 98.
 * if file_to cannot be created  to - exit code 99.
 * if file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buff(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);
	free(buffer);
	cloose_file(from);
	cloose_file(to);
	return (0);
}
