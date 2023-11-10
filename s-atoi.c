#include "shell.h"

/**
 * interactive - function check that returns as true if it is in
 * interactive mode
 *
 * @list: address to the struct list
 *
 * Return: 1 if in interactive mode, 0 if not
 *
int interactive(info_t *list)
{
	return (isatty(STDIN_FILENO) && list->readfd <= 2);
}
*/
/**
 * is_delim - function that checks if a character is a delimiter
 *
 * @c: character to be checked
 * @delim: pointer to the delimeter string
 *
 * Return: 1 if true, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - function that checks for an alphabet
 *
 * @c: character to be checked
 *
 * Return: 1 if its an alphabet, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function that converts string to an integer
 *
 * @str: pointer to the string to be converted
 *
 * Return: 0 if no numbers are in string, otherwise, it convertse
 */

int _atoi(char *str)
{
	int index, sign = 1, flag = 0, output;
	unsigned int numeric_result = 0;

	/*skip leading whitespace*/
	for (index = 0; str[index] == ' '; index++)

	/*check for sign*/
	if (str[index] == '-')
	{
		sign *= -1;
		index++;
	}
	/* convert digits to integer */
	for (;  str[index] != '\0' && flag != 2; index++)
	{
		if (str[index] >= '0' && str[index] <= '9')
		{
			flag = 1;
			numeric_result *= 10;
			numeric_result += (str[index] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}
	/* apply sign to the result */
	if (sign == -1)
		output = -numeric_result;
	else
		output = numeric_result;

	return (output);
}
char *_itoa(int a)
{
	char buffer[20];
	int i = 0;

	if (a == 0)
		buffer[i++] = '0';
	else
	{
		while (a > 0)
		{
			buffer[i++] = (a % 10) + '0';
			a /= 10;
		}
	}
	buffer[i] = '\0';
	rev_string(buffer, i);
	return (_strdup(buffer));
}
void rev_string(char *str, int len)
{
    int i, j;
    char temp;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void write_error(char *name, char *cmd, int count)
{
	char *index;

	index = _itoa(count);

	_puts(name);
	_puts(": ");
	_puts(index);
	_puts(": ");
	_puts(cmd);
	_puts(": not found");
	_putchar('\n');

	free(index);
}