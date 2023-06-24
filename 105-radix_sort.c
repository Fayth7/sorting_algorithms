#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stddef.h>

/**
 * getMax - Get the maximum element in an array
 * @array: The array of integers
 * @size: The size of the array
 *
 * Return: The maximum element in the array
 */
int getMax(int *array, size_t size)
{
int max = array[0];
size_t i;

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
 * countSort - Perform count sort on an array based on a specific digit
 * @array: The array of integers
 * @size: The size of the array
 * @exp: The digit position to sort on
 *
 * Description: performs count sort on given array based on the
 * specified digit position (exp).
 */

void countSort(int *array, size_t size, int exp)
{
int *output = (int *)malloc(size * sizeof(int));
int count[10] = {0};
size_t i;

for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

for (i = 1; i < 10; i++)
count[i] += count[i - 1];

for (i = size - 1; i > 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}

for (i = 0; i < size; i++)
array[i] = output[i];

free(output);
}

/**
 * radix_sort - Sort an array of integers using Radix sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 *
 * Description: sorts the given array in ascending order using the
 * Radix sort algorithm.
 */

void radix_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

size_t exp = 1;
int max = getMax(array, size);

for (; max / exp > 0; exp *= 10)
{
countSort(array, size, exp);
print_array(array, size);
}
}
