#include "shell.h"

void write_error(char *name, char *cmd, int count)
{
	char *index;

	index = _itoa(count);

	_puts(name);
	_puts(": ");
	_puts(index);
	_puts(": ");
	_puts(cmd);
	_puts(": not found");
	_putchar('\n');

	free(index);
}
