#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - Does nothing
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * is_number - Checks if a string represents a number
 * @n: String to check
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;

	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (0);
	}

	return (1);
}

