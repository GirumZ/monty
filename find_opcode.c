#include "monty.h"

/**
 * find_opcode - finds the right opcode function
 * @opc: opcode to be matched with function
 * Return: pointer to the function selected
 */

void (*find_opcode(char *opc))(stack_t **satck, unsigned int line_number)
{
	instruction_t opc_fn[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i;

	for (i = 0 ; opc_fn[i].opcode ; i++)
	{
		if (strcmp(opc_fn[i].opcode, opc) == 0)
			break;
	}

	return (opc_fn[i].f);
}
