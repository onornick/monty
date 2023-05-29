#include "monty.h"

int main(int argc, char *argv[])
{

	instruction_t instructions[] = {
                {"push", push},
                {"pall", pall},
		{"pint", pint},
        	{"pop", pop},
        	{"swap", swap},
        	{"add", add},
       	 	{"nop", nop},
                {NULL, NULL}};

	FILE *file;
	int value;
	unsigned int line_number = 0;
	char buffer[BUFFER_SIZE];

	stack_t *stack = NULL;

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
		char *opcode;
		line_number++;
	        opcode = strtok(buffer, " \t\n");
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

			value = atoi(arg);
			push(&stack, value);

       		}

		else
		{
			execute_instruction(instructions, opcode, &stack, line_number);
        	}

	}

	fclose(file);
    	while (stack != NULL)
	{
		stack_t *current = stack;
		stack = stack->next;
		free(current);
	}

	return 0;
}
