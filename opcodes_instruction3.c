#include "monty.h"

/**
 * pstr -  prints the string starting at the top of the stack
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	ptr = *head;

	while (ptr && ptr->n > 0 && ptr->n < 128)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}
/**
 * pchar - prints the char at the top of the stack
 * @head: head of linked list
 * @line_number: line number
 *
 * Return: void
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * div - divides the second top element of the stack by the
 * top element of the stack.
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void _div(stack_t **head, unsigned int line_number)
{
	int index = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, index++)
		;

	if (index < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n /= (*head)->n;
	pop(head, line_number);
}

/**
 * mul - multiplies the second top element of the stack with the
 * top element of the stack.
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void mul(stack_t **head, unsigned int line_number)
{
	int index = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, index++)
		;

	if (index < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n *= (*head)->n;
	pop(head, line_number);
}
/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @head: head of linked list
 * @line_number: line number
 *
 * Return: void
 */
void mod(stack_t **head, unsigned int line_number)
{
	int index = 0;
	stack_t *ptr = NULL;

	ptr = *head;

	for (; ptr != NULL; ptr = ptr->next, index++)
		;

	if (index < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	ptr->n %= (*head)->n;
	pop(head, line_number);
}
