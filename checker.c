#include "monty.h"

code_arg_t allin;

/**
 * free_allin - clean the global variables
 *
 * Return: no return
 */
void free_allin(void)
{
	free_double(allin.head);
	free(allin.buffer);
	fclose(allin.fd);
}

/**
 * initiate_allin - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void initiate_allin(FILE *fd)
{
	allin.lifo = 1;
	allin.crnt = 1;
	allin.arg = NULL;
	allin.head = NULL;
	allin.fd = fd;
	allin.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
