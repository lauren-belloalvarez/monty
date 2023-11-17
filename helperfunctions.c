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
 * @opcode: opcode to be executed
 * @stack: pointer to pointer to stack
 *
 * Return: executed function
 */

void exe(char *opcode, stack_t **stack)
{
	void (*func)(stack_t **, unsigned int);

	func = get_opcode(opcode);

	if (func != NULL)
	{
		func(stack, 0);
	}
	else
	{
		fprintf(stderr, "Unknown instruction: %s\n", opcode);
		exit(EXIT_FAILURE);
	}
}
