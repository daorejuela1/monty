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
