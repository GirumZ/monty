#include "monty.h"
/**
 * add_dnodeint - adds node at the begining of a list
 * @head: the head of the list
 * @n: data element of the list
 *
 * Return: pointer to the new node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;

	if (head != NULL)
	{
		new->next = (*head);
		if (*head != NULL)
		{
			(*head)->prev = new;
		}
		*head = new;
	}
	else
		new->next = NULL;

	return (new);
}

/**
 * add_dnodeint_end - adds node at the end of a list
 * @head: the head of the list
 * @n: the data element of the node
 *
 * Return: the new node
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *current;

	current = (*head);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
		return (new);
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
	return (new);
}

/**
 * free_dlistint - frees a list
 * @head: head of the list
 */

void free_dlistint(stack_t *head)
{
	stack_t *current;

	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
