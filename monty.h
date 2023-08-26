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


/**file_analyze**/
void analyze_line(char *file_name);
void read_file(FILE *fn);
void find_fun(char *opc, char *value, int num_line, int fqs);
int tok_line(char *str_line, int num_line, int fqs);
void call_fun(opcode_fun fun_opc, char *opc, char *val, int num_line, int fqs);

/**function_stack.c**/
void add_stack(stack_t **newstack, __attribute__((unused))unsigned int ln_n);
void add_queue(stack_t **newstack, __attribute__((unused))unsigned int ln_n);
void print_stack(stack_t **stack, unsigned int line_n);
void print_top(stack_t **stack, unsigned int line_n);
void pop_f(stack_t **stack, unsigned int line_n);

/**functions_stack2.c**/
void swap_f(stack_t **stack, unsigned int line_n);
void add_f(stack_t **stack, unsigned int line_n);
void nop_f(stack_t **stack, unsigned int line_n);
void sub_f(stack_t **stack, unsigned int line_n);
void div_f(stack_t **stack, unsigned int line_n);

/**functions_stack3.c**/
void mod_f(stack_t **stack, unsigned int line_n);
void mul_f(stack_t **stack, unsigned int line_n);
void print_char(stack_t **stack, unsigned int line_n);
void print_str(stack_t **stack, __attribute__((unused))unsigned int line_n);



/**error_message.c**/
void print_err(int error_num, ...);
void print_err2(int error_num, ...);

/**handle_nodeslist.c**/
stack_t *create_node(int n);
void free_nodes(void);


#endif
