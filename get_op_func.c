#include "monty.h"

/**
 * get_op_func - Select the function according to the opcode.
 * @opcode: Pointer to the opcode.
 * @arg: Pointer to arg of file
 * @stack: Pointer to head of stack list
 * @line_number: Line number of file
 *
 * Return: 0 (success).
 */

void (*get_op_func(int line))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_fun[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{NULL, NULL}
	};

	int pos_op = 0;

	while (opcode_fun[pos_op].opcode)
	{
		if (strcmp(opcode_fun[pos_op].opcode, opcode[0]) == 0)
		{
			return (opcode_fun[pos_op].f);
		}
		pos_op++;
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, opcode[0]);
	free_grid(opcode);
	exit(EXIT_FAILURE);
}
