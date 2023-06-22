#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * element of the stack.
 * @stack: head of the stack
 * @line_number: line number
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *to_delete;

	to_delete = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't mod, stack too short\n");
		termi_global();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		termi_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(to_delete);
}
