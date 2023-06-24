#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current;
    current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current->prev;
        int value = current->n;

        while (temp != NULL && temp->n > value)
        {
            temp->next->n = temp->n;
            temp = temp->prev;
        }

        if (temp == NULL)
            (*list)->n = value;
        else
            temp->next->n = value;

        print_list(*list);
        current = current->next;
    }
}
