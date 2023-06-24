#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

int compare_cards(const void *a, const void *b);

void sort_deck(deck_node_t **deck)
{
    int num_cards = 0;
    deck_node_t *current = *deck;
    deck_node_t **nodes;
    int i;

    while (current != NULL)
    {
        num_cards++;
        current = current->next;
    }

    nodes = (deck_node_t **)malloc(num_cards * sizeof(deck_node_t *));
    if (nodes == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    current = *deck;
    for (i = 0; i < num_cards; i++)
    {
        nodes[i] = current;
        current = current->next;
    }

    qsort(nodes, num_cards, sizeof(deck_node_t *), compare_cards);

    *deck = nodes[0];
    for (i = 0; i < num_cards - 1; i++)
    {
        nodes[i]->next = nodes[i + 1];
        nodes[i + 1]->prev = nodes[i];
    }
    nodes[num_cards - 1]->next = NULL;

    free(nodes);
}

int compare_cards(const void *a, const void *b)
{
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;

    if (node_a->card->kind < node_b->card->kind)
        return -1;
    if (node_a->card->kind > node_b->card->kind)
        return 1;

    return strcmp(node_a->card->value, node_b->card->value);
}
