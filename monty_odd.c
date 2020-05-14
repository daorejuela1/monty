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
	int data_length = 0;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_all();
	}
	for (data_length = 0; tmp != NULL; data_length++)
	{
		tmp = tmp->next;
	}
	if (data_length < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_all();
	}
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->n = tmp->prev->n ^ tmp->n;
	tmp->n = tmp->prev->n ^ tmp->n;
	tmp->prev->n = tmp->prev->n ^ tmp->n;
}
