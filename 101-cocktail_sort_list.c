#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    if (!node2->prev)
        *list = node2;

    print_list((const listint_t *)*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort algorithm
 * @list: Pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        start = *list;

        while (start->next != end) {
            if (start->n > start->next->n) {
                swap_nodes(list, start, start->next);
                swapped = 1;
            } else {
                start = start->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end = start;

        while (end->prev != NULL) {
            if (end->n < end->prev->n) {
                swap_nodes(list, end->prev, end);
                swapped = 1;
            } else {
                end = end->prev;
            }
        }
    } while (swapped);
}
