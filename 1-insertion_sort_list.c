#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: the given doubly linked list to work with
 */
void insertion_sort_list(listint_t **list)
{
	bool signal = false;
	listint_t *start = NULL, *temp_node = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	start = *list;
	while (start->next)
	{
		if (start->n > start->next->n)
		{
			start->next->prev = start->prev;
			if (start->next->prev)
				start->prev->next = start->next;
			else
				*list = start->next;

			start->prev = start->next;
			start->next = start->next->next;
			start->prev->next = start;
			if (start->next)
				start->next->prev = start;

			start = start->prev;
			print_list(*list);

			if (start->prev && start->prev->n > start->n)
			{
				if (!signal)
					temp_node = start->next;
				signal = true;
				start = start->prev;
				continue;
			}
		}
		if (!signal)
			start = start->next;
		else
			start = temp_node, signal = false;
	}
}
