#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);

print_array(array, n);
printf("\n");
counting_sort(array, n);
printf("\n");
print_array(array, n);
return (0);
}

/**
 * counting_sort - Sort an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
int *count_array = NULL, *sorted_array = NULL;
int max_value = 0, i, j;

if (array == NULL || size < 2)
return;

for (i = 0; i < (int)size; i++)
{
if (array[i] > max_value)
max_value = array[i];
}

count_array = malloc((max_value + 1) * sizeof(int));
if (count_array == NULL)
return;

sorted_array = malloc(size * sizeof(int));
if (sorted_array == NULL)
{
free(count_array);
return;
}

for (i = 0; i <= max_value; i++)
count_array[i] = 0;

for (i = 0; i < (int)size; i++)
count_array[array[i]]++;

for (i = 1; i <= max_value; i++)
count_array[i] += count_array[i - 1];

print_array(count_array, max_value + 1);
printf("\n");

for (j = size - 1; j >= 0; j--)
{
sorted_array[count_array[array[j]] - 1] = array[j];
count_array[array[j]]--;
}

for (i = 0; i < (int)size; i++)
array[i] = sorted_array[i];

free(count_array);
free(sorted_array);
}
