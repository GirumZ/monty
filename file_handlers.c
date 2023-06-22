#include "monty.h"
/**
 * check_file - checks if the arrgument given is a correct monty file
 * @argc: number of arguments
 * @argv: vector of arguments
 *
 * Return: 0 on success and 1 on failure
 */

int check_file(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (1);
	}
	if (access(argv[1], F_OK & R_OK) != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (1);
	}
	return (0);
}

/**
 * file_open - opens a file
 * @file_name: name of the file
 * Return: the file discripter on success and NULL on failure
 */

FILE *open_file(char *file_name)
{
	FILE *fd;

	fd = fopen(file_name, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (NULL);
	}
	return (fd);
}
