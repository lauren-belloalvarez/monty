#include "monty.h"

/**
 * m_push - adds element to top of stack
 *
 * @stack: points to top node of stack_t linked list
 * @line_number: current line in bytecodes file
 * @arg: argument passed to push
 *
 * Return: no value, modifies stack
 */

void m_push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	int i, value;
	stack_t *new_node;

	if ((*stack == NULL) || (*stack != NULL && (*stack)->n == 0))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	argument = strtok(NULL, " \n");
	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; argument[i] != '\0'; i++)
	{
		if (!isdigit(argument[i]) && argument[i] != '-' && argument[i] != '+')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	value = atoi(argument);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * m_pall - prints all values in a stack
 *
 * @stack: points to top node of stack_t linked list
 * @line_number: current line in bytecodes file
 *i
 * Return: prints stack
 */

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack; /*temporary pointer to top of stack*/
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n); /*prints value of current node*/
		current = current->next;
	}
}

/**
 * m_pint - prints top element of stack
 *
 * @stack: points to top node of stack
 * @line_number: current line in bytecode file
 *
 * Return: top element of stack
 */

void m_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * m_pop - removes top element of stack
 *
 * @stack: points to top node of stack
 * @line_number: current line in bytecode file
 *
 * Return: stack without top element
 */

void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tpoint;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tpoint = *stack; /*temporary pointer to top node*/
	*stack = (*stack)->next; /*updates pointer to next node removing top node*/

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tpoint);
}

/**
 * m_swap - swaps top two elements
 *
 * @stack: points to top node of stack
 * @line_number: current line in bytecode file
 *
 * Return: stack with top two elements swapped
 */

void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *next_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next_node = top->next;

	top->prev = next_node;
	top->next = next_node->next;
	next_node->prev = NULL;
	next_node->next = top;
	*stack = next_node;
}

