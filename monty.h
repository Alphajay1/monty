#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the function
 * @lifo: is a stack or queue
 * @current: current line
 * @arg: second par inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node
 * for stack, queues, LIFO, FIFO
 */
typedef struct globals
{
	int lifo;
	unsigned int current;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t glob_var;

void free_glob_var(void);
void start_glob_var(FILE *fd);
FILE *check_input(int argc, char *argv[]);


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void queue(stack_t **head, unsigned int line_number);
void stack(stack_t **head, unsigned int lin_numbere);
void _div(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);

void(*opcode_gets(char *opcode))(stack_t **stack, unsigned int line_number);

int _sch(char *str, char c);
char *_strtok(char *str, char *delim);
int _strcmp(char *str1, char *str2);

stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

void free_glob_var(void);

#endif
