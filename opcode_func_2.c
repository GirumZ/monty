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
/**
 * sub - subtracts the top element of the stack from the second
 * top element of the stack.
 * @stack: head of the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *to_delete;

	to_delete = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't sub, stack too short\n");
		termi_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(to_delete);
}
/**
 * div - divides the second top element of the stack by the top
 * element of the stack.
 * @stack: head of the stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *to_delete;

	to_delete = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't div, stack too short\n");
		termi_global();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		termi_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(to_delete);
}
/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack.
 * top element of the stack.
 * @stack: head of the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *to_delete;

	to_delete = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't mul, stack too short\n");
		termi_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(to_delete);
}
