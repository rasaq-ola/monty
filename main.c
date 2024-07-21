#include "monty.h"

#define BUFFER_SIZE 1024

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number);
char *custom_getline(FILE *file);

/**
 * main - Entry point of the Monty ByteCode interpreter
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    unsigned int line_number = 0;
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

    while ((line = custom_getline(file)) != NULL)
    {
        char *opcode;

        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode && opcode[0] != '#') /* Ignore comments and blank lines */
        {
            execute_instruction(opcode, &stack, line_number);
        }
        free(line);
    }

    free_stack(stack);
    fclose(file);
    return (EXIT_SUCCESS);
}

/**
 * custom_getline - Custom implementation of getline for C89 compatibility
 * @file: File pointer
 * Return: Pointer to the line read, or NULL on failure
 */
char *custom_getline(FILE *file)
{
    char *line = malloc(BUFFER_SIZE);
    if (line == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (fgets(line, BUFFER_SIZE, file) == NULL)
    {
        free(line);
        return NULL;
    }

    return line;
}
