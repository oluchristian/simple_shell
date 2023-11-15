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
 * is_positive - prints a character
 * @str: pointer to string
 *
 * Return: 1 if true, 0 if false.
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
