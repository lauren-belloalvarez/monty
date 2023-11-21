#include "monty.h"

void m_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_mode = MODE_STACK;
}

void m_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_mode = MODE_QUEUE;
}
