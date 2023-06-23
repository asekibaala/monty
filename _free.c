#include "monty.h"

/**
 * free_stack - Frees the memory allocated for the stack.
 */
void free_stack(void)
{
stack_t *current = stack;
while (current)
{
stack = current->next;
free(current);
current = stack;
}
}
