#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merge two sorted subarrays into one sorted array.
 * @array: The original array.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
size_t i;
size_t j = 0;
size_t k = 0;
size_t merged_size = left_size + right_size;
int *merged = malloc(sizeof(int) * merged_size);

if (merged == NULL)
return;

printf("Merging...\n");
printf("[left]: ");
print_array(left, left_size);
printf("[right]: ");
print_array(right, right_size);

for (i = 0; i < merged_size; i++)
{
if (j < left_size && (k >= right_size || left[j] <= right[k]))
{
merged[i] = left[j];
j++;
}
else
{
merged[i] = right[k];
k++;
}
}

for (i = 0; i < merged_size; i++)
{
array[i] = merged[i];
}

printf("[Done]: ");
print_array(merged, merged_size);

free(merged);
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
size_t mid;
int *left, *right;

if (array == NULL || size < 2)
return;

if (size > 1)
{
mid = size / 2;
left = array;
right = array + mid;

merge_sort(left, mid);
merge_sort(right, size - mid);

merge(array, left, mid, right, size - mid);
}

if (size == 2 && array[0] > array[1])
{
int temp = array[0];
array[0] = array[1];
array[1] = temp;
}

printf("\n");
print_array(array, size);
}
