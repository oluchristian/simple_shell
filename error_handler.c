#include "shell.h"
/**
 * write_error - write errors
 * @name: name
 * @cmd: command
 * @count: count
 * Return: void
 */
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
