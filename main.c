#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
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

	while ((read = getline(&line, &len, file)) != -1)
	{
		if (line[0] == '\n' || line[0] == '#')
		{
			line_number++;
			continue;
		}
		execute_instruction(&stack, line, line_number);
		line_number++;
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
} 
