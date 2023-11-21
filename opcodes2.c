#include "monty.h"

/**
 * m_add - adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;
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
 * m_div - divides the second top element of the stack by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	int divisor, result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / divisor;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	free(temp);
}

/**
 * m_mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
		line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n * (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;

	free(temp);
}

