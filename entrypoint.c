#include "monty.h"

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument value
 *
 * Return: monty program output
 */

int main(int argc, char **argv)
{
	mode_t data_mode = MODE_STACK;
	FILE *file;
	char opcode[1024];
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	stack_t *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(opcode, sizeof(opcode), file) != NULL)
	{
		exe(opcode, &stack, line_number);
		line_number++;
	}
	fclose(file);

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
