#include "monty.h"

/**
* mul_f - multiply top of elements
* @stack: list of nodes
* @line_n: line number
*/

void mul_f(stack_t **stack, unsigned int line_n)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_err2(8, line_n, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* mod_f - modolu top of elements
* @stack: list of nodes
* @line_n: line number
*/

void mod_f(stack_t **stack, unsigned int line_n)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		print_err2(8, line_n, "mod");


	if ((*stack)->n == 0)
		print_err2(9, line_n);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* print_char - print char
* @stack: list of nodes
* @line_n: line number
*/

void print_char(stack_t **stack, unsigned int line_n)
{
	int asciivalue;

	if (stack == NULL || *stack == NULL)
		print_err2(11, line_n);

	asciivalue = (*stack)->n;
	if (asciivalue < 0 || asciivalue > 127)
		print_err2(10, line_n);
	printf("%c\n", asciivalue);
}

/**
* print_str - print string
* @stack: list of nodes
* @line_n: line number
*/

void print_str(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	int asciivalue;
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	current = *stack;
	while (current != NULL)
	{
		asciivalue = current->n;
		if (asciivalue <= 0 || asciivalue > 127)
			break;
		printf("%c", asciivalue);
		current = current->next;
	}
	printf("\n");
}
