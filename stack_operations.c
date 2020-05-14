#include "monty.h"
/**
 * rotl - rotates stack to the left
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack, *origin = *stack;

	(void) line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->prev->next = NULL;
	tail->next = origin;
	tail->prev = NULL;
	origin->prev = tail;
	*stack = tail;
}
