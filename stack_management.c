#include "monty.h"

/**
* create_stack - create a new stack node
* @n: value to assign to the new node
* Return: pointer to the new node
*/

stack_t *create_stack(int n)
{
stack_t *node;
node = malloc(sizeof(stack_t));

if (node == NULL)
print_err(4);
node->next = NULL;
node->prev = NULL;
node->n = n;
return (node);
}

/**
* free_stack - free the entire stack
*/

void free_stack(void)
{
stack_t *current;

if (head == NULL)
return;

while (head != NULL)
{
current = head;
head = head->next;
free(current);
}
}
