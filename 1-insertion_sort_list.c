#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * @insertion_sort_list - sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
 * @list: pointer to the node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL)
                return;
	while (current)
	{
	
	listint_t *next_node = current->next;
	listint_t *prev_node = current->prev;

	while (prev_node && current->n < prev_node->n)
	{
	if (current->next)
	current->next->prev = current->prev;
	if (current->prev)
	current->prev->next = current->next;
	
	current->prev = prev_node->prev;
	current->next = prev_node;
	if (prev_node->prev)
	prev_node->prev->next = current;
	else
	*list = current;
	prev_node->prev = current;
	print_list(*list);
	prev_node = current->prev;
	}
	current = next_node;
