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
