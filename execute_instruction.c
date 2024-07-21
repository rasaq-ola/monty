#include "monty.h"

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

/**
 * execute_instruction - Executes a given opcode
 * @opcode: The opcode to execute
 * @stack: The stack to operate on
 * @line_number: The current line number in the bytecode file
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
    unsigned int i;

    for (i = 0; instructions[i].opcode; i++)
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
