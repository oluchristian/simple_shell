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


	/*?shell = get_info(argv[0], environ, &status, &count, interactive);*/
	if (interactive && argc > 1)
	{
		stream = fopen(argv[1], "r");

		if (!stream)
		{
			exit(1);
			/*handle error here*/
		}
	}
	else
		stream = stdin;

	while (1)
	{
		if (interactive && argc == 1)
			w = write(STDOUT_FILENO, prompt, 4);
		if (w == -1)
			return (1);
		/* Returns the char string read from stream*/
		bytesRead = read_line(stream);
		/* EOF Condition (Ctr + D)*/
		if (bytesRead == NULL)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		count++;
		if (bytesRead)
			/* cmdPreprocessor()*/
			removeComment(bytesRead);
		/* returns an array of tokenized command string */
		cmd = tokenize(bytesRead);
		free(bytesRead), bytesRead = NULL;
		if (cmd == NULL)
			continue;
		if (is_builtin(cmd[0]))
			exec_builtin(cmd, argv, &status, count);
		else
			status = _execute(cmd, argv, count);
	}
}
