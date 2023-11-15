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
    char **environ;
    int status;
    int count;
    int interactive;
} Info;

/************** StringsFormatter.c ******************/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *src);
int	_strlen(const char *str);
int	_strcmp(char *s1, char *s2);

/************** StringsFormatter-2.c ******************/
int _putchar(char c);
void _puts(char *str);
char *_itoa(int a);
int _atoi(char *str);
int is_positive(char *str);
void rev_string(char *str, int len);

/************** remove_comment.c ******************/
void removeComment(char *cmd);

/**************** free_array.c *******************/
void freeArray(char **array);

/**************** execute.c *******************/
int _execute(char **cmd, char **argv, int count);

/**************** error_handler.c *******************/
void write_error(char *name, char *cmd, int count);

/**************** builtins.c *******************/
void shell_exit(char **cmd, char **argv, int *status, int count);
void print_env(char **cmd, int *status);

/**************** builtin_handler.c *******************/
int is_builtin(char *cmd);
void exec_builtin(char **cmd, char **argv, int *status, int count);

/**************** s-getpath.c *******************/
char *get_path(char *command);
char		*_getenv(char *path);

/**************** checkPrompt.c *******************/
char **tokenize(char *bytesRead);
char *read_line(FILE *stream);

/*Info get_info(char *, char *, char **, int *, int *, int);*/
#endif
