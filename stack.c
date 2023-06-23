#include "monty.h"
/**
 * stack - Sets the mode of the data structure to stack (LIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number currently being executed
 *
 * Description: This function sets the mode of the data structure to stack
 *(LIFO).
 * It updates the global variable `current_queue` to STACK.
 * Return: Void
 */

void set_stack_mode(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    current_queue = STACK;
}
