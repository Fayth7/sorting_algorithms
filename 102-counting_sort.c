#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	size_t i;
	int max = array[0];

	/* Find the maximum element in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array of size max+1 and initialize it to 0 */
	int *count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	size_t j;

	for (j = 0; j <= max; j++)
		count[j] = 0;

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Modify the counting array to store the cumulative counts */
	for (j = 1; j <= (size_t)max; j++)
		count[j] += count[j - 1];

	/* Create a temporary output array */
	int *output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Build the output array using the counting array */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
