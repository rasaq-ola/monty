#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number of the current operation
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
