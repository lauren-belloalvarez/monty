#include "monty.h"

/**
 * get_opcode - obtains relevant opcode for execution
 *
 * @opcode: matched opcode
 * @f: function that handles opcode
 *
 * Return: pointer to function
 */

void *get_opcode(char *opcode)
{
	int count;

	instruction_t funcs[] =
	{
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{NULL, NULL}
	};
	for (count = 0; funcs[count].opcode; count++)
		if (strcmp(opcode, funcs[count].opcode) == 0)
			return (funcs[count]);
	return (NULL);
}
