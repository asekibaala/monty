#include "monty.h"

/**
 * process_file - reads an input file line by line and executes the
 * corresponding opcode
 * @filename: the name of the input file
 *
 * Description: This function opens the input file, reads each line of the file,
 * and executes the corresponding opcode
 * using a switch statement. The function also handles errors such as file not
 * found, invalid opcodes, and stack underflow.
 * The function frees the memory allocated for the stack and input file after
 * processing is complete.
 */
void process_file(char *filename)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
     fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
     while ((nread = getline(&line, &len, fp)) != -1) {
        line_number++;
         char *opcode = strtok(line, " \n\t\r");
        if (opcode == NULL || opcode[0] == '#') {
            continue;
        }
         if (strcmp(opcode, "push") == 0) {
            char *arg = strtok(NULL, " \n\t\r");
            if (arg == NULL || !is_number(arg)) {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, atoi(arg), line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(stack, line_number);
        } else if (strcmp(opcode, "pint") == 0) {
            pint(stack, line_number);
        } else if (strcmp(opcode, "pop") == 0) {
            pop(&stack, line_number);
        } else if (strcmp(opcode, "swap") == 0) {
            swap(&stack, line_number);
        } else if (strcmp(opcode, "add") == 0) {
            add(&stack, line_number);
        } else if (strcmp(opcode, "nop") == 0) {
            nop(stack, line_number);
        } else {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }
     free(line);
    fclose(fp);
    free_stack(stack);
}
