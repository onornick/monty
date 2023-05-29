#include "monty.h"

/**
 * execute_instruction - Executes the corresponding function for a given opcode.
 * @instructions: Array of instruction_t structures 
 * @opcode: Opcode to execute
 * @stack: Double pointer to the top of the stack
 * Description: Executes the corresponding function for a given opcode.
 * @line_number: Line number in the file
 */

void execute_instruction(instruction_t *instructions, char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
