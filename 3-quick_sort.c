#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Echange deux entiers dans un tableau
 * @a: Pointeur sur le premier entier
 * @b: Pointeur sur le deuxième entier
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Implémente le schéma de partition de Lomuto
 * @array: Tableau d'entiers à trier
 * @low: Indice bas de la partition
 * @high: Indice haut de la partition (pivot)
 * @size: Taille totale du tableau (pour afficher les changements)
 *
 * Return: L'indice final du pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /* Le pivot est le dernier élément*/
	int i = low - 1;         /* Indice de la fin de la zone "plus petits"*/
	int j = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - Récursion pour trier un tableau avec Quick Sort
 * @array: Tableau d'entiers à trier
 * @low: Indice bas de la partition
 * @high: Indice haut de la partition
 * @size: Taille totale du tableau
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_helper(array, low, pivot_index - 1, size);
		quick_sort_helper(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Trie un tableau d'entiers en ordre croissant avec Quick Sort
 * @array: Tableau d'entiers à trier
 * @size: Taille du tableau
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
