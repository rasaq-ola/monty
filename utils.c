#include "monty.h"

/**
 * free_stack - Frees a stack
 * @stack: The stack to free
 */
void free_stack(stack_t *stack)
{
    stack_t *current;

    while (stack)
    {
        current = stack;
        stack = stack->next;
        free(current);
    }
}

/**
 * is_number - Checks if a string is a number
 * @str: The string to check
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(const char *str)
{
    if (*str == '-' || *str == '+')
    {
        str++;
    }
    while (*str)
    {
        if (*str < '0' || *str > '9')
        {
            return (0);
        }
        str++;
    }
    return (1);
}
