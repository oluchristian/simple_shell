#include "shell.h"

int _execute(char **cmd, char **argv)
{
    int status, exec_status;
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        exec_status = execve(cmd[0], cmd, environ);

        if (exec_status == -1)
        {
            perror(argv[0]);
            freeArray(cmd);
            exit(0);
        }
    }
    /* wait for the child to run and then frees the cmd array */
    else
    {
        waitpid(pid, &status, 0);
        freeArray(cmd);
    }
    /* returns with a WEXITSTATUS code */
    return (WEXITSTATUS(status));
}
