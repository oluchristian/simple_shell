#ifndef SHELL_H
# define SHELL_H
# include <limits.h>
# include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define CMD_NOT_FOUND 127
#define DELIM " \t\n"


extern char	**environ;

void		startMyshell(void);
char **tokenize(char *bytesRead);
char *read_line(void);
int _execute(char **cmd, char **argv, int count);
void freeArray(char **array);
void removeComment(char *cmd);
char *get_path(char *command);
void write_error(char *name, char *cmd, int count);
void rev_string(char *str, int len);
char *_itoa(int a);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void _puts(char *str);
void		writeError(char *input);
void		writeExitError(char *nomber);
void		freeArgs(char **args);
void		executeCommands(char **args, char **envp, int *stat);
int			findFullPath(char *prompt, char **full_path);
void		waitChildprocess(int *stat);
char		*_getenv(char *path);
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