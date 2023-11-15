#include "shell.h"
/**
 * freeArray - frees arrays
 * @array: array
 * Return: void
 */
void freeArray(char **array)
{
	int i;

	if (array == NULL)
		return;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

