/**
 * int_index - Searches for an integer in an array.
 * @array: The array to be searched.
 * @size: The size of the array.
 * @cmp: A pointer to a comparison function.
 *
 * Return: If successful, returns the index of the first non-zero result from `cmp`.
 *         If no element matches, returns -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}

