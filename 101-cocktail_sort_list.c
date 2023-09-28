#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: the list to work with
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *left_limit = NULL, *right_limit = NULL;
	int cycle_type = INCRE;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = *list;
	left_limit = current;
	right_limit = dlistint_len(*list);

	while (left_limit != right_limit)
	{
		if (current->n == current->next->n)
			break;
		else if (current->n > current->next->n && cycle_type == INCRE)
			swap_nodes(list, current), print_list(*list);
		else if (current->next->n < current->n && cycle_type == DECRE)
		{
			swap_nodes(list, current);
			current = current->prev, print_list(*list);
		}
		else if (cycle_type == INCRE)
			current = current->next;
		else if (cycle_type == DECRE)
			current = current->prev;

		if (cycle_type == DECRE && current->next == left_limit)
			cycle_type = INCRE, current = current->next;

		if (cycle_type == INCRE && current->prev == right_limit)
		{
			right_limit = right_limit->prev;
			cycle_type = DECRE;
			current = current->prev;
		}
	}
}

/**
 * swap_nodes - swap two nodes of a doubly linked list
 * @list: the double linked lists thaat contains the nodes
 * @node: the node to swap with the next node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->next->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
 * dlistint_len - Count the elements of a distint_t list
 * @h: the given head pointer
 *
 * Return: the number of element in the list
 */
listint_t *dlistint_len(listint_t *h)
{
	listint_t *current = h;

	while (current->next != NULL)
		current = current->next;
	return (current);
}
