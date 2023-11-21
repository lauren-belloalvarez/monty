#include "monty.h"

/**
 * m_mod - computes the remainder of division of the second top element by
 * the top element
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	int divisor, remainder;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % divisor;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = remainder;

	free(temp);
}

/**
 * m_pchar - prints the char at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)((*stack)->n));
}

/**
 * m_pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", (char)current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * m_rotl - rotates the stack to the top
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void m_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	bottom = *stack;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	top = *stack;
	*stack = top->next;
	(*stack)->prev = NULL;

	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
}

/**
 * m_rotr - rotates the stack to the bottom
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	bottom = *stack;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	if (bottom->prev)
	{
		bottom->prev->next = NULL;
		bottom->prev = NULL;
		bottom->next = *stack;
		(*stack)->prev = bottom;
		*stack = bottom;
	}
}
