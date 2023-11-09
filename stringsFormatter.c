#include "shell.h"

/**
 * _strdup - Duplicate a string in memory
 * @src: Pointer to the source string to duplicate
 *
 * Description: This function duplicates a string in memory.
 *
 * Return: A pointer to the newly allocated
 * duplicated string, or NULL if memory allocation fails.
 */

char *_strdup(const char *src)
{
	char *ptr;
	int len = 0, i;

	if (src == NULL)
		return (NULL);
	while (*src != '\0')
	{
		len++;
		src++;
	}
	src = src - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = src[i];
	return (ptr);
}


/**
 * _strlen - Calculate the length of a string
 * @str: Pointer to the string
 *
 * Description: This function calculates the length of a string.
 *
 * Return: The length of the string.
 */

int _strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 *
 * Description: This function compares two strings.
 *
 * Return: 0 if the strings are equal, a
 * positive value if s1 is greater, and a negative value if s2 is greater.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}



/**
 * _atoi - Convert a string to an integer
 * @s: Pointer to the string to convert
 *
 * Description: This function converts a string to an integer.
 *
 * Return: The converted integer.
 */

int _atoi(char *s)
{
	int sign = 1, i;
	unsigned int res;

	sign = 1, i = 0;
	res = 0;
	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}

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
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/* betty style header for _getenv function */

/**
 * _getenv - Get the value of an environment variable
 * @path: Pointer to the environment variable name
 *
 * Description: This function retrieves.
 * the value of an environment variable
 *
 * Return: A pointer to the value of the environment
 * variable, or NULL if not found.
 */

char *_getenv(const char *path)
{
	int i;
	int len;

	len = _strlen((char *)path);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(path, environ[i], len))
		{
			if (environ[i][len] == '=')
			{
				return (environ[i] + len + 1);
			}
		}
	}
	return (NULL);
}
