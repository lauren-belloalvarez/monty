#include "monty.h"

/**
 * m_add - adds top two elements of stack
 *
 * @stack: points to top node
 * @line_number: current line of bytecode
 *
 * Return: stack with top two elements added
 */

void m_add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + ((*stack)->next)->n;
	(*stack)->next->n = sum;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = *stack;
	}
	free(temp);
}

/**
 * m_nop - does nothing
 *
 * @stack: points to top node
 * @line_number: current line of bytecode
 *
 * Return: original stack
 */

void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * m_sub - subtracts top element from second element in stack
 *
 * @stack: points to top node
 * @line_number: current line of bytecode
 *
 * Return: subraction result as top element
 */

void m_sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next)->n - (*stack)->n;
	(*stack)->next->n = result;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * m_div - divides second element by top element in stack
 *
 * @stack: points to top node
 * @line_number: current line of bytecode
 *
 * Return: stack with top element as resultant
 */

void m_div(stack_t **stack, unsigned int line_number)
{
	int divisor, result;
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	divisor = (*stack)->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next)->n / divisor;
	(*stack)->next->n = result;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

