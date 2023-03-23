#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    while ((nread = getline(&line, &len, file)) != -1) {
        line_number++;

        // Remove trailing newline character
        if (line[nread-1] == '\n') {
            line[nread-1] = '\0';
            nread--;
        }

        if (nread > 0) {
            if (execute(line, &stack, line_number, file) == -1) {
                fprintf(stderr, "Error: execution failed on line %u\n", line_number);
                free(line);
                free_stack(stack);
                fclose(file);
                return EXIT_FAILURE;
            }
        }
    }

    free(line);
    free_stack(stack);
    fclose(file);

    return EXIT_SUCCESS;
}
