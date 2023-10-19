#include "monty.h"

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t num_lines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	initiate_allin(fd);
	num_lines = getline(&allin.buffer, &size, fd);
	while (num_lines != -1)
	{
		lines[0] = _strtoky(allin.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", allin.crnt);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_allin();
				exit(EXIT_FAILURE);
			}
			allin.arg = _strtoky(NULL, " \t\n");
			f(&allin.head, allin.crnt);
		}
		num_lines = getline(&allin.buffer, &size, fd);
		allin.crnt++;
	}

	free_allin();

	return (0);
}
