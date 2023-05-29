#include "monty.h"

/**
 * pint - opcode prints the value at the top of the stack.
 * Descripton: opcode prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
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

/**
 * swap - opcode swaps the top two elements of the stack.
 * Description: opcode swaps the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
}

