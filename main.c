#include "monty.h"

global_t glob;

/**
 * main - entry point for the program
 * @argc: number of arguments
 * @argv: vector of arguments
 *
 * Return: 0 on success and 1 on failure
 */

int main(int argc, char **argv)
{
	int file_check;
	FILE *fp;
	char *opcode_array[2] = {NULL, NULL};
	void (*f)(stack_t **stack, unsigned int line_number);

	file_check = check_file(argc, argv);
	if (file_check == 1)
		exit(EXIT_FAILURE);

	fp = open_file(argv[1]);
	if (fp == NULL)
		exit(EXIT_FAILURE);

	init_global();
	glob.fp = fp;
	glob.buff = read_line(fp);

	while (glob.buff)
	{
		opcode_array[0] = strtok(glob.buff, " \t\n");
		opcode_array[1] = strtok(NULL, " \t\n");
		if (opcode_array[0] && opcode_array[0][0] != '#')
		{
			f = find_opcode(opcode_array[0]);
			if (f == NULL)
			{
				fprintf(stderr, "L%u: ", glob.cline);
				fprintf(stderr, "unknown instruction %s\n", opcode_array[0]);
				termi_global();
				exit(EXIT_FAILURE);
			}
			glob.arg = opcode_array[1];
			f(&glob.head, glob.cline);
		}
		free(glob.buff);
		glob.buff = read_line(fp);
		glob.cline++;
	}

	termi_global();
	return (0);
}
