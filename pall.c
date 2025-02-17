#include "monty.h"

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number of the current operation
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
