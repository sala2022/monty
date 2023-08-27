#include "monty.h"

/**
* add_stack - function to add stack
* @newstack: new node
* @ln_num: line
*/

void add_stack(stack_t **newstack, __attribute__((unused))unsigned int ln_num)
{
	stack_t *current;

	if (newstack == NULL || *newstack == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newstack;
		return;
	}
	current = head;
	head = *newstack;
	head->next = current;
	current->prev = head;
}

/**
* add_queue - add to queue
* @newstack: new node
* @ln_num: line number
*/

void add_queue(stack_t **newstack, __attribute__((unused))unsigned int ln_num)
{
	stack_t *current;

	if (newstack == NULL || *newstack == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newstack;
		return;
	}
	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = *newstack;
	(*newstack)->prev = current;
}

/**
* print_stack - print all n node in stack
* @stack: list of nodes
* @line_number: line number
*/

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
* print_top - print the top of stack
* @stack: list of nodes
* @line_number: line number
*/

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
* pop_top - pop the top of stack
* @stack: list of nodes
* @line_number: line number
*/

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		print_err(7, line_number);

	current = *stack;
	*stack = current->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
