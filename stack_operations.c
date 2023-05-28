#include "monty.h"

/* Function: pop
 * ---------------------
 * The pop opcode removes the top element of the stack.
 *
 * stack: Double pointer to the top of the stack
 * line_number: Line number in the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/* Function: push
 * ---------------------
 * The push opcode pushes an element to the stack.
 *
 * stack: Double pointer to the top of the stack
 * n: Integer value to push
 * line_number: Line number in the file
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

/* Function: pall
 * ---------------------
 * The pall opcode prints all the values on the stack, starting from the top.
 *
 * stack: Double pointer to the top of the stack
 * line_number: Line number in the file
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

/* Function: pint
 * ---------------------
 * The pint opcode prints the value at the top of the stack.
 *
 * stack: Double pointer to the top of the stack
 * line_number: Line number in the file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/* Function: swap
 * ---------------------
 * The swap opcode swaps the top two elements of the stack.
 *
 * stack: Double pointer to the top of the stack
 * line_number: Line number in the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
