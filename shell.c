#include "shell.h"


/**
 * main - Entry point of the shell program
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
	int fd, bytesRead, interactive = isatty(STDIN_FILENO);
	size_t size = 0;
	size_t size_prompt = 0;
	char *prompt = NULL;
	int status = 0;
	FILE *stream;
	info shell_info;

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
	{
		stream = stdin;
	}
	while (1)
	{
		if (interactive && argc == 1)
			write(STDOUT_FILENO, "($) ", 4);
		bytesRead = getline(&prompt, &size, stream);

		if (bytesRead < 0)
		{
			putchar('\n');
			free(prompt);
			if (stream != stdin)
				fclose(stream);
			prompt = NULL;
			exit(EXIT_SUCCESS);
		}
		printf("%s", prompt);
	}
	return (0);
}
