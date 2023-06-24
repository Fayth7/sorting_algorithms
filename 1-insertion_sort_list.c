#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted, *curr, *temp, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	unsorted = (*list)->next;
	while (unsorted != NULL)
	{
		curr = unsorted;
		temp = curr->prev;

		while (temp != NULL && temp->n > curr->n)
		{
			prev = temp->prev;
			next = curr->next;

			if (prev != NULL)
				prev->next = curr;
			else
				*list = curr;

			if (next != NULL)
				next->prev = temp;

			temp->next = next;
			temp->prev = curr;
			curr->next = temp;
			curr->prev = prev;

			print_list(*list);

			temp = prev;
		}

		unsorted = unsorted->next;
	}
}
