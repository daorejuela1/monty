#include "monty.h"

/**
 * push - adds a new node at the end of a stack_t list.
 * @stack: pointer to head element of list
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
		free_all(*stack, opcode);
	}
	for (i = 0; opcode[1][i] != 0; i++)
	{
		if (opcode[1][i] < '0' || opcode[1][i] > '9')
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			free_all(*stack, opcode);
		}
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
		free_all(*stack, opcode);
	}
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
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
	stack_t *tmp = *stack;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
		return;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	for (num = 0; tmp != NULL; num++)
	{
		if (tmp == NULL)
			return;

		printf("%i\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * free_stack - Free a list.
 * @stack: pointer to head element of list
 *
 * Return: Nothing
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp, *store;

	tmp = stack;

	while (tmp != NULL)
	{
		store = tmp->next;
		free(tmp);
		tmp = store;
	}
}

/**
 * free_all - Free a list.
 * @stack: pointer to head element of list
 * @grid: pointer to char matrix
 *
 * Return: Nothing
 */
void free_all(stack_t *stack, char **grid)
{
	free_grid(grid);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
