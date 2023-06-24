#include <stdio.h>
#include <stdlib.h>

void merge(int *left, size_t left_size, int *right, size_t right_size, int *merged);
void merge_sort_recursive(int *array, size_t size, int *temp);
void merge_sort(int *array, size_t size);

void merge(int *left, size_t left_size, int *right, size_t right_size, int *merged)
{
    size_t i, j, k;

    for (i = 0, j = 0, k = 0; i < left_size && j < right_size; k++)
    {
        if (left[i] <= right[j])
            merged[k] = left[i++];
        else
            merged[k] = right[j++];
    }

    while (i < left_size)
        merged[k++] = left[i++];

    while (j < right_size)
        merged[k++] = right[j++];
}

void merge_sort_recursive(int *array, size_t size, int *temp)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    size_t left_size = mid;
    size_t right_size = size - mid;

    int *left = array;
    int *right = array + mid;

    merge_sort_recursive(left, left_size, temp);
    merge_sort_recursive(right, right_size, temp);

    printf("Merging...\n");
    printf("[left]: ");
    size_t i;
    for (i = 0; i < left_size; i++)
        printf("%d ", left[i]);
    printf("\n");

    printf("[right]: ");
    for (i = 0; i < right_size; i++)
        printf("%d ", right[i]);
    printf("\n");

    merge(left, left_size, right, right_size, temp);

    printf("[Done]: ");
    for (i = 0; i < size; i++)
    {
        array[i] = temp[i];
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");
}

void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *temp = (int *)malloc(size * sizeof(int));
    if (temp == NULL)
        return;

    merge_sort_recursive(array, size, temp);
    free(temp);
}
