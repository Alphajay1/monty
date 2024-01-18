#include "monty.h"

global_t glob_var;

void free_glob_var(void);
void start_glob_var(FILE *fd);
FILE *check_input(int argc, char *argv[]);

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number)
	FILE *fd;
	size_t size = 256;
	ssize_t n_lines = 0;
	char *line[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_glob_var(fd);
	n_lines = getline(&glob_var.buffer, &size, fd);
	while (n_lines != -1)
	{
		line[0] = _strtok(glob_var.buffer, "\t\n");
		if (line[0] && line[0][0] != '#')
		{
			f = opcode_gets(line[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glob_var.current);
				dprintf(2, "unknown instruction %s\n", line[0]);
				free_glob_var();
				exit(EXIT_FAILURE);
			}
			glob_var.arg = _strtok(NULL, "\t\n");
			f(&glob_var.head, glob_var.current);
		}
		n_lines = getline(&glob_var.buffer, &size, fd);
		glob_var.current++;
	}
	free_glob_var();

	return (0);
}

/**
 * free_glob_var - frees the global variable
 */
void free_glob_var(void)
{
	free_dlistint(glob_var.head);
	free(glob_var.buffer);
	fclose(glob_var.fd);
}

/**
 * start_glob_var - initializes the global variable
 * @fd: file descriptor
 *
 * Return: void
 */
void start_glob_var(FILE *fd)
{
	glob_var.lifo = 1;
	glob_var.current = 1;
	glob_var.arg = NULL;
	glob_var.head = fd;
	glob_var.buffer = NULL;
}

/**
 * check_input - checks if the file exist and if the file can be opened
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
