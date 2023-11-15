#include "shell.h"

/**
 * main - Entry point of the shell progra
 *
 * Description: This function is the entry point of the shell program.
 * It reads user input and processes the commands either interactively
 * or in non-interactive mode based on whether the standard input is a TTY.
 *
 * @argc: number of arguments passed
 * @argv: array of arguments passed
 *
 * Return: Always 0 to indicate successful execution.
 */
int main(int argc, char **argv)
{
	int status = 0, count = 0, interactive = isatty(STDIN_FILENO);
	char  *prompt = "(s) ", **cmd = NULL, *bytesRead = NULL;
	ssize_t w = 0;
	FILE *stream = NULL;
	Info shell;

	shell = get_info(&status, interactive, stream);
	if (interactive && argc > 1)
	{
		shell.stream = fopen(argv[1], "r");
		if (!shell.stream)
			exit(1);
	}
	else
		shell.stream = stdin;
	while (1)
	{
		if (interactive && argc == 1)
			w = write(STDOUT_FILENO, prompt, 4);
		if (w == -1)
			return (1);
		/* Returns the char string read from stream*/
		bytesRead = read_line(shell);
		/* EOF Condition (Ctr + D)*/
		if (bytesRead == NULL)
			return (shell.status);
		count++;
		if (bytesRead)
			removeComment(bytesRead);
		/* returns an array of tokenized command string */
		cmd = tokenize(bytesRead);
		free(bytesRead), bytesRead = NULL;
		if (cmd == NULL)
			continue;
		if (is_builtin(cmd[0]))
			exec_builtin(cmd, argv, shell, count);
		else
			status = _execute(cmd, argv, count);
	}
}
