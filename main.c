#include "monty.h"

int main(int argc, char *argv[])
{

	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *file;
        file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFER_SIZE];
	unsigned int line_number = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	while (fgets(buffer, BUFFER_SIZE, file))
	{
		line_number++;
		char *opcode = strtok(buffer, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
	        {
			char *arg = strtok(NULL, " \t\n");
			if (arg == NULL || !is_number(arg))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);

			}

			int value = atoi(arg);
			push(&stack, value);

       		}

		else
		{
			execute_instruction(instructions, opcode, &stack, line_number);
        	}

	}

	fclose(file);
	return 0;
}
