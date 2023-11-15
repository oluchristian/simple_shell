#include "shell.h"
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
/**
 *_itoa - int
 *@a: the int character
 *
 * Return: characters
 */
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
/**
 *rev_string - reverses a string
 *@str: string to be reversed
 *@len: length of string
 *
 * Return: void
 */
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

