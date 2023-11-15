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
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates strings
 * @dest: base string
 * @src: string to concat to dest
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
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
