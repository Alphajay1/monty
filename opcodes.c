#include "monty.h"

/**
 * opcode_gets - selects the correct code to perform
 * @opcode: the opcode given
 *
 * Return: pointer to the functon that executes the opcode
 */
void (*opcode_gets(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"queue", queue},
		{"stack", stack},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	int i;

	for (i = 0; cmd[i].opcode; i++)
		if (_strcmp(cmd[i].opcode, opcode) == 0)
			break;
	return (cmd[i].f);
}
