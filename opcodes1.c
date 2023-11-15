#include "monty.h"

/**
 * m_push - adds element to top of stack
 *
 * @stack: points to top node of stack_t linked list
 * @line_number: current line in bytecodes file
 *
 * Return: no value, modifies stack
 */

void m_push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t)); /**new node memory allocation*/

	if (new_node == NULL) /*if memory allocation succesfull*/
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value; /*sets n to value*/
	new_node->prev = NULL; /*new node initially doesnt have previous value*/

	if (*stack == NULL) /*checks for empty stack*/
	{
		new_node->next = NULL; /*no nodes below it*/
	}
	else
	{
		new_node->next = *stack; /*sets current top to next*/
		(*stack)->prev = new_node; /*sets prev of current top to point to new node*/
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
 *
 */

void m_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
}
