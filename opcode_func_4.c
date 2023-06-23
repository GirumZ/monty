#include "monty.h"
/**
 * stack - set the mode to stack
 * @stack: the head of the stack
 * @line_number: line number
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	glob.s_q_switch = 1;
}
/**
 * queue - set the mode to stack
 * @stack: the head of the stack
 * @line_number: line number
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	glob.s_q_switch = 0;
}
