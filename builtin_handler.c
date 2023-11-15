#include "shell.h"

void exec_builtin(char **cmd, char **argv, int *status, int count)
{
    (void) argv;
    (void) count;
    
    if (_strcmp(cmd[0], "exit") == 0)
        shell_exit(cmd, argv, status, count);
    else if (_strcmp(cmd[0], "env") == 0)
        print_env(cmd, status);
}

int is_builtin(char *cmd)
{
    int i;

    char *builtins[] = {
        "exit", "cd" "setenv", "env", NULL
    };

    for (i = 0; builtins[i] != NULL; i++)
    {
        if (_strcmp(cmd, builtins[i]) == 0)
            return (1);
    }
    return (0);
}