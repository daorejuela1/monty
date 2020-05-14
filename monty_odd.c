#include "monty.h"

/**
 * pint - prints the value at top of the stack
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_all();
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	printf("%i\n", tmp->n);
}

/**
 * swap  - swap the value of the top stack values
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int i = 0, backup = 0;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_all();
	}
	for (i = 0; tmp->next != NULL; i++)
	{
		tmp = tmp->next;
	}
	if (i < 1)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_all();
	}
	backup = tmp->prev->n;
	tmp->prev->n = tmp->n;
	tmp->n = backup;
}
