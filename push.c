#include "monty.h"
/**
  * push - Pushes an element to the stack
  * @argc: The number of command line arguments
  * @argv: The array of command line arguments
  *
  * Usage: push <int>
  *
  * Return: 0 on success, or EXIT_FAILURE on failure
  */
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("L%d: usage: push integer\n", __LINE__);
        exit(EXIT_FAILURE);
    }

    int value = atoi(argv[1]);

    printf("Pushing %d to the stack\n", value);

    return (0);
} 
