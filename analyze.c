#include "monty.h"

/**
 * analyze_line - open file
 * @file_name: string of name
 */
void analyze_line(char *file_name)
{
    FILE *fn;

    if (file_name == NULL)
        print_err(2, file_name);
    if (access(file_name, R_OK) == -1)
        print_err(2, file_name);
    fn = fopen(file_name, "r");
    if (fn == NULL)
        print_err(2, file_name);
    read_file(fn);
    fclose(fn);
}

/**
 * read_file - read file lines
 * @fn: file detector
 */
void read_file(FILE *fn)
{
    char *str_line = NULL;
    size_t len = 0;
    int n_line = 1;
    int fqs = 0;

    while (getline(&str_line, &len, fn) != -1)
    {
        fqs = tok_line(str_line, n_line, fqs); 
        n_line++;
    }
    free(str_line);
}

/**
 * tok_line - tokenize the line
 * @str_line: line string
 * @num_line: line number
 * @fqs: format is queue or stack
 * Return: return 1 if queue or 0 if stack
 */
int tok_line(char *str_line, int num_line, int fqs)
{
    const char *delim = " \n\t\a\b";
    char *opcode;
    char *value;

    if (str_line == NULL)
        print_err(3);
    opcode = strtok(str_line, delim);
    if (opcode == NULL)
        return (fqs);
    value = strtok(NULL, delim);
    if (strcmp(opcode, "queue") == 0)
        return (1);
    else if (strcmp(opcode, "stack") == 0)
        return (0);
    find_fun(opcode, value, num_line, fqs);
    return (fqs);
}

/**
* find_fun - function finder from list
* @opcode: opcode
* @value: value
* @num_line: line number
* @fqs: format is queue or stack
*/

void find_fun(char *opcode, char *value, int num_line, int fqs)
{
        int f = 1, i = 0;
instruction_t func_list[] = {
                {"push", add_stack},
                {"pall", print_stack},
                {"pint", print_top},
                {"pop", pop_f},
                {"swap", swap_f},
                {"add", add_f},
                {"nop", nop_f},
                {"sub", sub_f},
                {"div", div_f},
                {"mul", mul_f},
                {"mod", mod_f},
                {"pchar", print_char},
                {"pstr", print_str},
                {NULL, NULL}
        };
        if (opcode[0] == '#')
                return;
        while (func_list[i].opcode != NULL)
        {
                if (strcmp(opcode, func_list[i].opcode) == 0)
                {
                        call_fun(func_list[i].f, opcode, value, num_line, fqs);
                        f = 0;
                }
                i++;
 }
        if (f == 1)
                print_err(3, num_line, opcode);
}

/**
* call_fun - function call
* @fun_op: opcode function
* @op: opcode
* @val: value
* @num_line: line number
* @fqs: format is queue or stack
*/

void call_fun(opcode_fun fun_op, char *op, char *val, int num_line, int fqs)
{
        stack_t *stack;
        int f;
        int i;

        f = 1;
        if (strcmp(op, "push") == 0)
        {
                if (val != NULL && val[0] == '-')
                {
                        val = val + 1;
                        f = -1;
                }
              if (val == NULL)
                        print_err(5, num_line);
                for (i = 0; val[i] != '\0'; i++)
                {
                        if (isdigit(val[i]) == 0)
                                print_err(5, num_line);
                }
                stack = create_node(atoi(val) * f);
                if (fqs == 0)
                        fun_op(&stack, num_line);
                if (fqs == 1)
                        add_queue(&stack, num_line);
        }
        else
                fun_op(&head, num_line);
}
