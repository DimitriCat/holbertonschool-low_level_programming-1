#include "holberton.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: A pointer to a read only array of characters.
 * @letters: An unsigned integer value indicating number of chars to read and
 * print.
 * Return: A signed integer value indicating number of chars printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t count;
	char *buf;

	buf = malloc(sizeof(size_t) * letters);
	if (buf == NULL || filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	count = read(fd, buf, letters);
	if (count == -1)
		return (0);
	count = write(STDOUT_FILENO, buf, count);
	if (count == -1)
		return (0);
	buf[letters - 1] = '\0';
	close(fd);

	return (count);
}
