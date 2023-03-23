#include "monty.h"
/**
* execute - Executes the monty commands
* @content: string of the commands
* @stack: Stack to be manipulated
* @counter: counter of the lines
* @file: File
* Return: nothing
*/
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	char *token;
	int i;
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", divide},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{NULL, NULL}
	};

	token = strtok(content, DELIM);
	if (token == NULL || token[0] == '#')
		return;
	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(token, ops[i].opcode) == 0)
		{
			ops[i].f(stack, counter, file);
			break;
		}
	}
	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", counter, token);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
