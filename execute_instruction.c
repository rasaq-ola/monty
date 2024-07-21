#include "monty.h"

/**
 * execute_instruction - Executes a Monty opcode
 * @stack: Double pointer to the stack
 * @opcode: Opcode to execute
 * @line_number: Line number in the Monty bytecode file
 */
void execute_instruction(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
