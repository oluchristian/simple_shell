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
/**
 *is_positive - checks if a number is positive
 *@str: the character to check
 *
 * Return: 1 if +ve or 0
 */
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

