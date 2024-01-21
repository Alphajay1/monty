#include "monty.h"

/**
 * rotl - rotates the first element to the bottom and the second to the top.
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: void
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *ptr1 = NULL;
	stack_t *ptr2 = NULL;
	(void)line_number;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	ptr1 = (*head)->next;
	ptr2 = *head;

	for (; ptr2->next != NULL; ptr2 = ptr2->next)
		;

	ptr1->prev = NULL;
	ptr2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = ptr2;
	*head = ptr1;
}

/**
 * rotr -  last element of the stack becomes the top element of the stack
 * @head: head of linked list
 * @line_number: line number
 *
 * Return: void
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = NULL;
	(void)line_number;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	ptr = *head;

	for (; ptr->next != NULL; ptr = ptr->next)
		;

	ptr->prev->next = NULL;
	ptr->next = *head;
	ptr->prev = NULL;
	(*head)->prev = ptr;
	*head = ptr;
}
