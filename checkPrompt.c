#include "shell.h"

char *read_line(void)
{
	FILE *stream;
	char *buffer = NULL;
	size_t buff_size = 0;
	ssize_t bytesRead;

	stream = stdin;
	bytesRead = getline(&buffer, &buff_size, stream);
	if (bytesRead == -1)
	{
		if (stream != stdin)
			fclose(stream);

		free(buffer);
		return (NULL);
	}
	/*if (buffer[bytesRead - 1] == '\n')
		buffer[bytesRead - 1] = '\0';*/

	return (buffer);
}

 char **tokenize(char *bytesRead)
{
	char *token = NULL, **cmd = NULL, *tmp = NULL;
	int i = 0, token_count = 0;

	if (bytesRead == NULL)
		return (NULL);
	tmp = _strdup(bytesRead);
	token = strtok(tmp, DELIM);

	if (token == NULL)
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
	free(bytesRead), bytesRead = NULL;
	cmd[i] = NULL;
	return (cmd);
}