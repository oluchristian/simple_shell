#include "shell.h"
/**
 * get_path - gets value of the environment variable
 * @command: environment variable
 *
 * Return: file path or command or NULL
 */
char *get_path(char *command)
{
	char *path, *duplicate_path, *path_token, *file_path;
	size_t command_length, directory_length, i;
	struct stat buffer;

	path = _getenv("PATH");

	if (path)
	{
		duplicate_path = _strdup(path);
		if (duplicate_path)
		{
			command_length = _strlen(command);
			/**Tokenize the path to get all directories*/
			path_token = strtok(duplicate_path, ":");
			while (path_token != NULL)
			{
				directory_length = _strlen(path_token);
				file_path = malloc(command_length + directory_length + 2);
				if (file_path)
				{
					_strcpy(file_path, path_token);
					_strcat(file_path, "/");
					_strcat(file_path, command);
					_strcat(file_path, "\0");
					
					if (stat(file_path, &buffer) == 0)
					{
						free(duplicate_path);
						free(path);
						return (file_path);
					}
					free(file_path), file_path = NULL;
				}
				path_token = strtok(NULL, ":");
			}
			free(duplicate_path);
			free(path);
			/* If the command is an existing path */
			for (i = 0; command[i]; i++)
			{
				if (command[i] == '/')
				{
					if (stat(command, &buffer) == 0)
						return (_strdup(command));
					return (NULL);
				}
			}
		}
	}
	return (NULL);
}

