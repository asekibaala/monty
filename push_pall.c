#include "monty.h"
/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push_stack(stack, atoi(arg));
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	(void) line_number; /*unused parameter*/

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
