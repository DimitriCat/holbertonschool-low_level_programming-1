#include "function_pointers.h"

/**
 * int_index - Searches for an integer
 *
 * @array: A pointer to an array of integers.
 * @size: An integer value.
 * @cmp: A pointer to a function.
 *
 * Return: An integer value
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);
	if (size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
