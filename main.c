#include "monty.h"

/**
* main - main of the program
* @argc: number of arguments
* @argv: content of arguments
* Return: return 0 if success
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	print_err(1);
	analyze_line(argv[1]);
	free_nodes();
	return (0);
}
