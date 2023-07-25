#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: The linked list.
 * @nodeA: The first node to be swapped.
 * @nodeB: The second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *nodeA, listint_t *nodeB)
{
	listint_t *prevA, *nextB;

	if (nodeA == NULL || nodeB == NULL)
		return;

	prevA = nodeA->prev;
	nextB = nodeB->next;

	if (prevA)
		prevA->next = nodeB;

	if (nextB)
		nextB->prev = nodeA;

	nodeA->next = nextB;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;
	nodeB->prev = prevA;

	if (prevA == NULL)
		*list = nodeB;
}

/**
 *insertion_sort_list-Sorts a doubly linked list of integers in ascending order
 *using the insertion sort algorithm.
 *
 * @list: The list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *current;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current)
	{
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			swap_nodes(list, prev, current);
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}

