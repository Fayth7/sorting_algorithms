#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b);

void bitonic_merge(int *array, size_t size, int dir);

void bitonic_sort_recursive(int *array, size_t size, int dir);

void bitonic_sort(int *array, size_t size);

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bitonic_merge(int *array, size_t size, int dir)
{
  if (size > 1)
    {
      size_t half = size / 2;
      size_t i;
      printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
      print_array(array, size);
      for (i = 0; i < half; i++)
	{
	  if ((array[i] > array[i + half]) == dir)
	    swap(&array[i], &array[i + half]);
	}
      bitonic_merge(array, half, dir);
      bitonic_merge(array + half, half, dir);
    }
}

void bitonic_sort_recursive(int *array, size_t size, int dir)
{
  if (size > 1)
    {
      size_t half = size / 2;

      bitonic_sort_recursive(array, half, 1);
      bitonic_sort_recursive(array + half, half, 0);

      bitonic_merge(array, size, dir);
    }
}

void bitonic_sort(int *array, size_t size)
{
  bitonic_sort_recursive(array, size, 1);
}
