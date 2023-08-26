#include "monty.h"

/**
* print_err1 - print errors
* @error_number: print error depend on number
*/

void print_err1(int error_number, ...)
{
	va_list arg;
	char *op;
	int number;

	va_start(arg, error_number);
	switch (error_number)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char *));
			break;
		case 3:
			number = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", number, op);
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
* @error_number: print error depend on number
*/

void print_err2(int error_number, ...)
{
	va_list arg;
	char *op;
	int number;

	va_start(arg, error_number);
	switch (error_number)
	{
		case 8:
			number = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", number, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					 va_arg(arg, unsigned int));
			break;
		case 10:
			number = va_arg(arg, int);
			fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
			break;
		case 11:
			number = va_arg(arg, int);
			fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
			break;
		default:
			break;
	}
	va_end(arg);
	exit(EXIT_FAILURE);
}
