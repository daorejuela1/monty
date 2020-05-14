#include "monty.h"

/**
 * pop - adds a new node at the top of a stack_t list.
 * @stack: pointer to head element of list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
                current = current->next;
	if (current->prev != NULL)
		current->prev->next = NULL;
	else
		*stack = NULL;
	free(current);
	current = NULL;
}
