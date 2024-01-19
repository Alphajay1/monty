#include "monty.h"

/**
 * add_dnodeint - add a node at the beginning of the doubly linked list
 * @head: head of the linked list
 * @n: data
 *
 * Return: a doubly linked list.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list
 * @head: head of the list
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}

/**
 * add_dnodeint_end - adds node at end of doubly linked list
 * @head: head of linked list
 * @n: data
 *
 * Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *ptr;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;

	temp->next = ptr->next;
	temp->prev = ptr;
	ptr->next = temp;
	return (ptr->next);
}
