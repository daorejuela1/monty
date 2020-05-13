#include "monty.h"
#define BUFFER_SIZE 1024
/**
 * main - This receives the data path
 * from the monty file.
 * @ac: quantity of arguments received.
 * @av: filepath of the monty bytecode.
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	FILE *fd;
	ssize_t n;
	struct stat st;
	char buf[BUFFER_SIZE], **opcode = NULL, *result = NULL;
	int data_length = 0, line_counter = 1;
	stack_t *head = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (stat(av[1], &st) != 0 || access(av[1], R_OK) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	fd = open_file(av[1]);
	while (fgets(buf, BUFFER_SIZE, fd) != NULL)
	{
		opcode = extract_string(buf, &data_length);
		pointer_to_function = get_op_func(line_counter);
		if (pointer_to_function != NULL)
			(*pointer_to_function)(&head, line_counter);
		line_counter++;
		free_grid(opcode);
		data_length = 0;
	}
	fclose(fd);
	return (0);
}
