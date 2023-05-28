#include "monty.h"

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


void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

int is_number(const char *n)
{
	int i = 0;
	if (*n == '-')
	i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return 0;
	}

    	return (1);
}
