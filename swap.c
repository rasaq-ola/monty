#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number of the current operation
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = *stack;
    }
    temp->next = *stack;
    temp->prev = NULL;
    (*stack)->prev = temp;
    *stack = temp;
}
