#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number of the current operation
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
