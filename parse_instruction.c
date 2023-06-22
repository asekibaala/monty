#include "monty.h"

/** parse_instruction - Parses a line of instruction into an array of strings
 * @line: The line of instruction to parse
 *
 * Return: An array of strings representing the individual instructions
 */
char **parse_instruction(char *line)
{
    char **instruction;
    char *token;
    int i = 0;
    instruction = malloc(sizeof(char *) * 3);
    if (instruction == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, " \n\t");
    while (token != NULL && i < 2)
    {
        instruction[i] = token;
        i++;
        token = strtok(NULL, " \n\t");
    }
    instruction[i] = NULL;
    return (instruction);
}
