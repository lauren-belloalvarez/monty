#include "monty.h"

/**
 * get_opcode - obtains relevant opcode for execution
 *
 * @opcode: matched opcode
 *
 * Return: pointer to function
 */

void (*get_opcode(char *opcode))(stack_t **, unsigned int)
{
	int count = 0;

	instruction_t funcs[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"push", m_push},
		{"stack", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};

	while (funcs[count].opcode != NULL)
	{
		if (strcmp(funcs[count].opcode, opcode) == 0)
		{
			return (funcs[count].f);
		}
		count++;
	}
	return (NULL);
}

/**
 * exe - executes opcode
 *
 * @line: line of char
 * @stack: pointer to pointer to stack
 * @line_number: number of lines
 *
 * Return: executed function
 */
void exe(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	void (*func)(stack_t **, unsigned int);

	while (isspace((unsigned char)*line))
	{
		line++;
	}

	if (*line == '#' || *line == '\0')
	{
		return;
	}

	opcode = strtok(line, " \n\t");
	if (opcode == NULL)
		return;

	func = get_opcode(opcode);
	if (func != NULL)
	{
		func(stack, line_number);
	} else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
		opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_number - checks if a string is a valid integer
 * @str: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
