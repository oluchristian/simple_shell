#ifndef SHELL_H
# define SHELL_H
# include <limits.h>
# include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define DELIM " \t\n"


extern char	**environ;

void		startMyshell(void);
char **tokenize(char *bytesRead);
char *read_line(void);
/*void removeComment(char *cmd);*/
int _execute(char **cmd, char **argv);
void freeArray(char **array);
void		writeError(char *input);
void		writeExitError(char *nomber);
void		freeArgs(char **args);
void		executeCommands(char **args, char **envp, int *stat);
int			findFullPath(char *prompt, char **full_path);
void		waitChildprocess(int *stat);
char		*_getenv(const char *path);
void		printEnviron(void);
void		nonInteractMode(char *token, int *status);
char		**funcTokenize(char *str, char *delim);
void		setEnvironmentVariable(char *variable,  char *value);

void		unsetEnvironmentVariable(char *variable);

void		funcExitStatus(int stat, char **args, char **token, int *status);

void		getPromptFail(char *prompt);

char		*_strdup(const char *src);
int	_strlen(const char *str);
int			_strcmp(char *s1, char *s2);
int			_atoi(char *s);
int _putchar(char c);
#endif
