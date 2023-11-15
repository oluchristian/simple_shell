#include "shell.h"
/**
 * read_line - rread line
 * @stream: stream
 * Return: char
 */
char *read_line(FILE *stream)
{

	char *buffer = NULL;
	size_t buff_size = 0;
	ssize_t bytesRead;

	bytesRead = getline(&buffer, &buff_size, stream);
	if (bytesRead == -1)
	{
		if (stream != stdin)
			fclose(stream);

		free(buffer);
		return (NULL);
	}
	/*
	 * if (buffer[bytesRead - 1] == '\n')
	 * buffer[bytesRead - 1] = '\0';
	 **/

	return (buffer);
}
/**
 * tokenize - print env variables
 * @bytesRead: char of bytes
 * Return: token
 */
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
		free(tmp);
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
		return (NULL);
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
