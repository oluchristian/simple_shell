#include "shell.h"

void shell_exit(char **cmd, char **argv, int *status, int count)
{
    int exit_val = (*status);
    char *index, err_msg[] = ": exit: Illegal number: ";

    if (cmd[1])
    {
        if (is_positive(cmd[1]))
            exit_val = _atoi(cmd[1]);
        else
        {
            index = _itoa(count);
            write(STDERR_FILENO, argv[0], _strlen(argv[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, index, _strlen(index));
            write(STDERR_FILENO, err_msg, _strlen(err_msg));
            write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
            write(STDERR_FILENO, "\n", 1);
            free(index);
            freeArray(cmd);
            (*status) = 2;

            return;
        }
    }
    freeArray(cmd);
    exit(exit_val);
}
void print_env(char **cmd, int *status)
{
    int i;
    (void) status;

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    freeArray(cmd);
    (*status) = 0;
}

/**
 * cd_handler - This handles cd
 * @arguements: arguments passed to cd
 * Return: 0 on success, -1 on failure
 */
int cd_handler(char **cmd, int *status)
{
	char *directory;
	char cwd[PATH_MAX];
    (void) status;

	if (!cmd[1])
	{
		directory = _getenv("HOME");
		if (!directory)
			directory = "/";
	}
	else if (_strcmp(cmd[1], "-") == 0)
	{
		directory = _getenv("OLDPWD");
		if (!directory)
		{
			write(STDERR_FILENO, "cd: OLDPWD not set\n", 18);
			return (EXIT_FAILURE);
		}
	}
	else
		directory = cmd[1];

	if (chdir(directory) == -1)
	{
		perror("cd");
		return (-1);
	}

	setenv("OLDPWD", _getenv("PWD"), 1);

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	setenv("PWD", cwd, 1);
    (*status) = 0;
	return (0);
}