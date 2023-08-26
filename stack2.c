#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}


/**
 * swap_f - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: Interger representing the line number of of the opcode.
 */
void swap_f(stack_t **stack, unsigned int line_n)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_n, "swap");
	current = (*stack)->next;
	(*stack)->next = current->next;
	if (current->next != NULL)
		current->next->prev = *stack;
	current->next = *stack;
	(*stack)->prev = current;
	current->prev = NULL;
	*stack = current;
}

/**
 * add_f - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: Interger representing the line number of of the opcode.
 */
void add_f(stack_t **stack, unsigned int line_n)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_n, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_f - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: Interger representing the line number of of the opcode.
 */
void sub_f(stack_t **stack, unsigned int line_n)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_n, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_f - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: Interger representing the line number of of the opcode.
 */
void div_f(stack_t **stack, unsigned int line_n)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_n, "div");

	if ((*stack)->n == 0)
		more_err(9, line_n);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
