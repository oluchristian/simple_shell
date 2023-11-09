#include "shell.h"

char *read_line(void)
{
	FILE *stream;
	char *buffer = NULL, *line;
	size_t buff_size = 0;
	ssize_t bytesRead;
	int interactive = isatty(STDIN_FILENO);

	stream = stdin;
	bytesRead = getline(&buffer, &buff_size, stream);
	if (bytesRead == -1)
	{
		if (interactive)
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		if (stream != stdin)
			fclose(stream);
		buffer = NULL;
		exit(EXIT_SUCCESS);
	}
	if (buffer[bytesRead - 1] == '\n')
		buffer[bytesRead - 1] = '\0';

	line = _strdup(buffer);
	free(buffer);
	return (line);
}

 char **tokenize(char *bytesRead)
{
	char *token = NULL, **cmd = NULL, *tmp = NULL;
	int i = 0, token_count = 0;

	if (bytesRead == NULL)
		return (NULL);
	tmp = _strdup(bytesRead);
	token = strtok(tmp, DELIM);
	if (!token)
	{
		free(bytesRead), tmp = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		token_count++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (token_count + 1));
	if (!cmd)
	{
		free(bytesRead), bytesRead = NULL;
		return (NULL);
	}
	token = strtok(bytesRead, DELIM);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

void freeArray(char **array)
{
	int i;

	if (array == NULL)
		return;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
/* void removeComment(char *cmd) */
/* {
	* size_t len, i;

	if (cmd != NULL)
	{
		len = _strlen(cmd);
		cmd[len - 1] = '\0';

		for (i = 0; cmd[i] != '\0'; i++)
		{
			if (cmd[i] == '#')
			{
				cmd[i] = '\0';
				break;
			}
		}
		return (len = _strlen(cmd));
	}
	else
		perror("ERROR: CMD NULL");
}
*/