#include "monty.h"
/**
 * m_stack - Sets the data structure to operate as a stack (LIFO).
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the script file.
 */
void m_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_mode = MODE_STACK;
}
/**
 * m_queue - Sets the data structure to operate as a queue (FIFO).
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the script file.
 */
void m_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_mode = MODE_QUEUE;
}
