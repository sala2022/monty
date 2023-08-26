#include "monty.h"

/**
* print_err - print errors
* @error_num: print error depend on number
*/

void print_err(int error_num, ...)
{
	va_list arg;
	char *op;
	int l_num;

	va_start(arg, error_num);
	switch (error_num)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char *));
			break;
		case 3:
			l_num = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					 va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					 va_arg(arg, int));
			break;
		default:
			break;
	}
	va_end(arg);
	exit(EXIT_FAILURE);
}

/**
* print_err2 - print errors
* @error_num: print error depend on number
*/

void print_err2(int error_num, ...)
{
	va_list arg;
	char *op;
	int l_num;

	va_start(arg, error_num);
	switch (error_num)
	{
		case 8:
			l_num = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					 va_arg(arg, unsigned int));
			break;
		case 10:
			l_num = va_arg(arg, int);
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			l_num = va_arg(arg, int);
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	va_end(arg);
	exit(EXIT_FAILURE);
}
