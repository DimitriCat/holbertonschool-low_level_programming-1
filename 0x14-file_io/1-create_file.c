#include "holberton.h"

/**
 * create_file - Creates a file
 *
 * @filename: A pointer to an empty file to be created.
 * @text_content: A pointer to a NULL terminated string.
 *
 * Return: An integer 1 for success, -1 for failure.
 */
int create_file(const char *filename, char *text_content)
{
	int result, fd, len;
	char *buf;

	if (filename == NULL || text_content == NULL)
		return (-1);
	for (len = 0; text_content[len] != '\0';)
		len++;
	buf = malloc(sizeof(char) * len);
	if (buf == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY, 0600);
	if (fd == -1)
		return (fd);
	result = write(fd, text_content, len);
	if (result == -1)
		return (result);
	return (1);
}