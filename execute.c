#include "shell.h"
/**
 * _execute - execve
 * @cmd: command
 * @argv: argv
 * @count: count
 * Return: pid
 */
int _execute(char **cmd, char **argv, int count)
{
	int status, exec_status;
	pid_t pid;
	char *file_path;
	
	file_path = get_path(cmd[0]);
	if (!file_path)
	{
		write_error(argv[0], cmd[0], count);
		freeArray(cmd);
		return (CMD_NOT_FOUND);
	}
	pid = fork();
	if (pid == 0)
	{
		exec_status = execve(file_path, cmd, environ);
		
		if (exec_status == -1)
		{
			free(file_path), file_path = NULL;
			freeArray(cmd);
		}
	}
	/* wait for the child to run and then frees the cmd array */
	else
	{
		waitpid(pid, &status, 0);
		freeArray(cmd);
		free(file_path), file_path = NULL;
	}
	/* returns with a WEXITSTATUS code */
	return (WEXITSTATUS(status));
}

