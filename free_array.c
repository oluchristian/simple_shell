#include "shell.h"

/**
 * freeArray - function that frees an array
 * @array: array to be freed
 *
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
