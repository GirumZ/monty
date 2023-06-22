#include "monty.h"
/**
 * read_line - reads a line from a file
 * @fp: file pointer
 * Return: the content of the line
 */

char *read_line(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t true_read;

	true_read = getline(&line, &len, fp);
	if (true_read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
