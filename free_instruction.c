#include "monty.h"

/**
 * free_instruction - Frees the memory used by the instruction array
 * @instruction: The instruction array to free
 */
void free_instruction(char **instruction)
{
    free(instruction);
}
