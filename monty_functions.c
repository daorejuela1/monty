#include "monty.h"

/**
 * push - adds a new node at the end of a stack_t list.
 * @head: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *tmp = *stack;
	int i;
	new = malloc(sizeof(stack_t));

	if (opcode[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_grid(opcode);
		exit (EXIT_FAILURE);
	}

	for (i = 0; opcode[1][i] != 0; i++)
	{
		if (opcode[1][i] < '0' || opcode[1][i] > '9')
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			free_grid(opcode);
			exit (EXIT_FAILURE);
		}
		else
			continue;
	}

	if (new != NULL)
	{
		new->n = atoi(opcode[1]);
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_grid(opcode);
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
	int num = 0;
	(void) line_number;

	for (num = 0; stack != NULL; num++)
	{
		if (stack == NULL || *stack == NULL)
			return;
		else
			printf("%i\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
