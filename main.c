#include "monty.h"

/**
 * main - entry point of the program
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 * Description: test cases
 *
 *
 */

instruction_t instruction[] = {
                {"pop", pop},
                {"pall", pall},
                {"pint", pint},
                {"swap", swap},
                {"push", push},
                {"add", add},
                {"nop", nop},
                {NULL, NULL}
        };


int main(int argc, char *argv[])
{
	FILE *file;
	int value;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char buffer[BUFFER_SIZE], *opcode, *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, BUFFER_SIZE, file))
	{
		line_number++;
		opcode = strtok(buffer, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL || !is_number(arg))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, value);
		}
		else
			execute_instruction(instruction, opcode, &stack, line_number);
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}

/**
 * free_stack - Free a stack
 * @stack: The stack to free
 * Return: Nothing
 * Description: This function frees the memory allocated for the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

