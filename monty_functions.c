#include "monty.h"

/**
 * push - adds a new node at the end of a stack_t list.
 * @head: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */

void push(stack_t **stack, char *num, unsigned int line_number)
{
	stack_t *new = NULL, *tmp = *stack;

	new = malloc(sizeof(stack_t));

	if (new != NULL)
	{
		new->n = atoi(num);
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		new->prev = tmp;
		tmp->next = new;
	}
}

/**
 * pall - prints all elements of a stack ist.
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t num = 0;

	for (num = 0; stack != NULL; num++)
	{
		if (stack == NULL || *stack == NULL)
			return;
		else
			printf("%i\n", stack->n);
		stack = stack->next;
	}
}
