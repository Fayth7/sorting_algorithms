#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
 listint_t *sorted;
    listint_t *unsorted;
    listint_t *curr;
    listint_t *temp;
    
  if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    sorted = *list;
    unsorted = (*list)->next;

    while (unsorted != NULL)
    {
        curr = unsorted;
        unsorted = unsorted->next;

        while (curr->prev != NULL && curr->n < curr->prev->n)
        {
            temp = curr->prev;
            temp->next = curr->next;

            if (curr->next != NULL)
                curr->next->prev = temp;

            curr->prev = temp->prev;
            curr->next = temp;
            temp->prev = curr;

            if (curr->prev != NULL)
                curr->prev->next = curr;
            else
                sorted = curr;

            print_list(*list);
        }
    }

    *list = sorted;
}
