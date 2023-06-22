#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: head of the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *to_delete;

	to_delete = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't add, stack too short\n");
		termi_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(to_delete);
}
/**
 * nop - does nothing
 * @stack: head of the stack
 * @line_number: line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
