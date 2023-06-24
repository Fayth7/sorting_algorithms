#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(int *list, int size)
{
    int i, j, temp;

    for (i = 1; i < size; i++)
    {
        temp = list[i];
        j = i - 1;

        while (j >= 0 && list[j] > temp)
        {
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = temp;

        for (j = 0; j < size - 1; j++)
            printf("%d, ", list[j]);
        printf("%d\n", list[j]);
    }
}

int main(void)
{
    int list[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int size = sizeof(list) / sizeof(list[0]);
    int i;

    for (i = 0; i < size - 1; i++)
        printf("%d, ", list[i]);
    printf("%d\n\n", list[i]);

    insertion_sort_list(list, size);

    return 0;
}
