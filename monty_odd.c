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

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
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

/**
 * nop  - does nothing
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - prints the top character of the stack
 * @stack: pointer to head element of stack list
 * @line_number: Line number of file
 *
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty", line_number);
		free_all();
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	if (tmp->n < 0 || tmp->n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range", line_number);
		free_all();
	}
	printf("%c\n", (char)tmp->n);

}
