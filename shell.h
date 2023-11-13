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

typedef struct
{
    char *name;
    char *file;
    char **environ;
    int ret_val;
    int count;
    int isatty;
} Info;


char **tokenize(char *bytesRead);
char *read_line(FILE *stream);
int _execute(char **cmd, char **argv, int count);
void freeArray(char **array);
void removeComment(char *cmd);
char *get_path(char *command);
void write_error(char *name, char *cmd, int count);
void rev_string(char *str, int len);
char *_itoa(int a);
int _atoi(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void _puts(char *str);
Info get_info(char *, char *, char **, int *, int *, int);
void shell_exit(char **cmd, char **argv, int *status, int count);
void get_env(char **cmd, int *status);
void exec_builtin(char **cmd, char **argv, int *status, int count);
int is_builtin(char *cmd);
int is_positive(char *str);
char		*_getenv(char *path);
char		*_strdup(const char *src);
int	_strlen(const char *str);
int			_strcmp(char *s1, char *s2);
int _putchar(char c);
#endif