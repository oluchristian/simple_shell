#include "shell.h"

/**
 * removeComment - function checks if a comment is present in a command
 * and removes it
 * @cmd: Pointer to command string
 *
 * Return: void
 */
void removeComment(char *cmd)
{
	size_t len, i;

	if (cmd != NULL)
	{
		len = _strlen(cmd);
		cmd[len - 1] = '\0';

		for (i = 0; cmd[i] != '\0'; i++)
		{
			if (cmd[0] == '#' || (cmd[i] == '#' && cmd[i - 1] == ' '))
			{
				cmd[i] = '\0';
				break;
			}
		}
	}
	else
		perror("ERROR: CMD NULL");
}
