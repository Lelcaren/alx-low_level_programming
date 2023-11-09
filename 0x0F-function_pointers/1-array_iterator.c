#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - prints each element of an array on a new line.
 * @array: The array to be printed.
 * @size: The number of elements to print.
 * @action: A pointer to a function that takes an integer as an argument.
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array == NULL || action == NULL)
		return;

	unsigned int i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}

