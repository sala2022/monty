#ifndef MONTY_H
#define MONTY_H


#define  _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

typedef void (*opcode_fun)(stack_t **, unsigned int);

extern stack_t *head;


/**file_handler**/
void parse_line(char *file_name);
void read_file(FILE *fd);
void fun_finder(char *opcode, char *value, int n_line, int fmt);
int tokenize_line(char *line_str, int n_line, int fmt);
void fun_call(opcode_fun fun_op, char *op, char *val, int n_line, int fmt);

/**function_stack.c**/
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln_num);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln_num);
void print_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);

/**functions_stack2.c**/
void swap_nodes(stack_t **stack, unsigned int line_num);
void add_nodes(stack_t **stack, unsigned int line_num);
void nop_nothing(stack_t **stack, unsigned int line_num);
void sub_nodes(stack_t **stack, unsigned int line_num);
void div_nodes(stack_t **stack, unsigned int line_num);

/**functions_stack3.c**/
void mod_nodes(stack_t **stack, unsigned int line_num);
void mul_nodes(stack_t **stack, unsigned int line_num);
void print_char(stack_t **stack, unsigned int line_num);
void print_str(stack_t **stack, __attribute__((unused))unsigned int line_num);



/**error_message.c**/
void print_err(int error_num, ...);
void print_err2(int error_num, ...);

/**handle_nodeslist.c**/
stack_t *create_node(int n);
void free_nodes(void);


#endif
