#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number of the current operation
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !is_number(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(arg);
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}
