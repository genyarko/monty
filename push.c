#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number of the file
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    int n;

    if (stack == NULL)
        return;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    if (strlen(tokens[1]) == 0)
    {
        printf("L%d: usage: push integer\n", line_number);
        free(new_node);
        exit(EXIT_FAILURE);
    }
    n = atoi(tokens[1]);
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}
