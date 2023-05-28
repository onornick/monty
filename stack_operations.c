#include "monty.h"

/**
 * push - pushes an element to the stack
 * ---------------------
 * Description: pushes an element to the stack
 * push - pushes an element to the stack
 * @stack: Double pointer to the top of the stack
 * @n: Integer value to push
 */

void push(stack_t **stack, unsigned int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - print all values
 * Description: opcode prints all the values on the stack
 * ---------------------
 * The pall opcode prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

