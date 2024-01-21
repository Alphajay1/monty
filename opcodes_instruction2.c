#include "monty.h"

/**
 * nop - doesn't do anything
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the second
 * top element of the stack.
 * @head: head of the linked list
 * @line_number: line number
 * Return: void
 */
void sub(stack_t **head, unsigned int line_number)
{
	int index = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, index++)
		;

	if (index < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n -= (*head)->n;
	pop(head, line_number);
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	glob_var.lifo = 0;

}

/**
 * stack - sets the format of the data to a stack (LIFO).
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	glob_var.lifo = 1;

}

/**
 * add - adds the top two elements of the stack.
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	int index = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, index++)
		;

	if (index < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n += (*head)->n;
	pop(head, line_number);
}
