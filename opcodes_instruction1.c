#include "monty.h"

/**
 * push - pushes an element to the stack
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void push(stack_t **head, unsigned int line_number)
{
	int n, j;

	if (!glob_var.arg)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glob_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(glob_var.arg[j]) && glob_var.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_glob_var();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob_var.arg);

	if (glob_var.lifo == 1)
		add_dnodeint(head, n);
	else
		add_dnodeint_end(head, n);
}

/**
 * pall - prints all values on the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: nothing
 */
void pint(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pick, stack empty\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the top element of the stack
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = (*head)->next;
	free(ptr);
}

/**
 * swap - swaps the top two elements of the stack
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	int i = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	*head = (*head)->next;
	ptr->prev = *head;
	(*head)->next = ptr;
	(*head)->prev = NULL;
}
