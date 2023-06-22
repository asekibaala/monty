#include "monty.h"

/**
 * execute_instruction - Executes the given instruction
 * @instruction: The instruction to execute
 */
void execute_instruction(char **instruction)
{
    int i = 0;
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"sub", sub},
        {"div", div_op},
        {"mul", mul},
        {"mod", mod},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},
        {"rotr", rotr},
        {"queue", queue},
        {"stack", stack},
        {NULL, NULL}
    };
    while (opcodes[i].opcode != NULL)
    {
        if (strcmp(instruction[0], opcodes[i].opcode) == 0)
        {
            opcodes[i].f(&stack, line_number);
            return;
        }
        i++;
    }
    printf("L%d: unknown instruction %s\n", line_number, instruction[0]);
    exit(EXIT_FAILURE);
}
