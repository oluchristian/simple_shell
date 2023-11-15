#include "shell.h"
/**
 * exec_builtin - execute builtin commands
 * @cmd: command
 * @argv: arguement
 * @status: status
 * @count: count
 * Return: void
 */
void exec_builtin(char **cmd, char **argv, int *status, int count)
{
	(void) argv;
	(void) count;
	if (_strcmp(cmd[0], "exit") == 0)
		shell_exit(cmd, argv, status, count);
	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, status);
}

/**
 * is_builtin - This handles builtin command
 * @cmd: command
 * Return: 0 on success
 */
int is_builtin(char *cmd)
{
	int i;
	char *builtins[] = {"exit", "cd", "setenv", "env", NULL};

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
			return (1);
	}
	return (0);
}
