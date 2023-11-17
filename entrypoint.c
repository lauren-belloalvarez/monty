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
	unsigned int line_number = 1;
	FILE *file;
	char opcode[100];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			stack_t *stack = NULL;

			while (fgets(opcode, sizeof(opcode), file) != NULL)
			{
				exe(opcode, &stack);
				line_number++;
			}
			fclose(file);
			while (stack != NULL)
			{
				stack_t *tpoint = stack;

				stack = stack->next;
				free(tpoint);
			}
			return (EXIT_SUCCESS);
		}
	}
}
