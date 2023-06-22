#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: head of the stack list
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i, data;

	if (glob.arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		termi_global();
		exit(EXIT_FAILURE);
	}
	for (i = 0 ; glob.arg[i] != '\0' ; i++)
	{
		if (!isdigit(glob.arg[i]) && glob.arg[i] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			termi_global();
			exit(EXIT_FAILURE);
		}
	}
	data = atoi(glob.arg);
	add_dnodeint(stack, data);
}
/**
 * pall - prints all elements of the stack
 * @stack: head of the stack list
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - prints the top element of the stack
 * @stack: head of the stack list
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		termi_global();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - deletes the top element of the stack
 * @stack: head of the stack list
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		termi_global();
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = (*stack)->next;
	free(current);
}

/**
 * swap - swaps the top two elements in the stack
 * @stack: head of the stack list
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		termi_global();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
