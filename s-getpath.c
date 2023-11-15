#include "shell.h"

/**
 * search_directories - function searches through directories
 * to find a specific path
 *
 * @path: Pointer to path string
 * @command: environment variable
 *
 * Return: file_path on success, NULL otherwise
 */
char *search_directories(char *path, char *command)
{
	char *duplicate_path, *path_token, *file_path;
	size_t command_lenght, directory_lenght;
	struct stat buffer;

	duplicate_path = _strdup(path);
	if (duplicate_path)
	{
		command_lenght = _strlen(command);
		/**Tokenize the path to get all directories*/
		path_token = strtok(duplicate_path, ":");
		while (path_token != NULL)
		{
			directory_lenght = _strlen(path_token);
			file_path = malloc(command_lenght + directory_lenght + 2);
			if (file_path)
			{
				_strcpy(file_path, path_token);
				_strcat(file_path, "/");
				_strcat(file_path, command);
				_strcat(file_path, "\0");

				if (stat(file_path, &buffer) == 0)
				{
					free(duplicate_path);
					return (file_path);
				}
				free(file_path);
				file_path = NULL;
			}
			path_token = strtok(NULL, ":");
		}
		free(duplicate_path);
	}
	return (NULL);
}

/**
 * get_path - gets value of the environment variable
 * @command: environment variable
 *
 * Return: file path or command or NULL
 */
char *get_path(char *command)
{
	char *path;
	size_t i;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		char *file_path = search_directories(path, command);

		if (file_path)
		{
			return (file_path);
		}
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
	return (NULL);
}

/* betty style header for _getenv function */

/**
 * _getenv - Get the value of an environment variable
 * @path: Pointer to the environment variable name
 *
 * Description: This function retrieves.
 * the value of an environment variable
 *
 * Return: A pointer to the value of the environment
 * variable, or NULL if not found.
 */

char *_getenv(char *path)
{
	int i;
	int is_path;
	char *tmp, *key, *value, *env;

	/*len = _strlen((char *)path);*/
	for (i = 0; environ[i] != NULL; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		is_path = _strcmp(key, path);
		if (is_path == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
