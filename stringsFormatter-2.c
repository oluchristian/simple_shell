#include "shell.h"

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 *_putchar - prints a character
 *@c: the character to be printed
 *
 * Return: number of characters written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
int is_positive(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
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

