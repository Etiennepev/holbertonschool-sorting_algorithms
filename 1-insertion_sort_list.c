#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * @insertion_sort_list - sort algorithm
 * description: sorts a doubly linked list of integers with sort algorithm
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
	/**
	* Détache le nœud courant de sa position actuelle
	*/
	if (current->next)
	current->next->prev = current->prev;
	if (current->prev)
	current->prev->next = current->next;
	/**
	* réinsère le noeud courant avant le noeud précédent
	*/
	current->prev = prev_node->prev;
	current->next = prev_node;
	if (prev_node->prev)
	prev_node->prev->next = current;
	else
	*list = current;
	prev_node->prev = current;
	/**
	* imprime la liste après chaque échange
	*/
	print_list(*list);
	/**
	* met à jour prev_node pour continuer à vérifier les noeuds précédents
	*/
	prev_node = current->prev;
	}
	/**
	 * passe au noeud suivant
	*/
	current = next_node;
	}
}
