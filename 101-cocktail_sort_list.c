#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: double pointer to list
 * Return: nothng
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *aux;
	int s = 1;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;
	aux = *list;
	while (s)
	{
		s = 0;
		while (aux->next != NULL)
		{
			if (aux->n > aux->next->n)
			{
				swap_list(aux, aux->next, list);
				++s;
				continue;
			}
			aux = aux->next;
		}
		aux = aux->prev;
		while (aux->prev != NULL)
		{
			if (aux->n < aux->prev->n)
			{
				swap_list(aux->prev, aux, list);
				++s;
				continue;
			}
			aux = aux->prev;
		}
	}
}
/**
 * swap_list - swap nodes in a doubly linked list
 * @tmp: element to be swapped with its previous node
 * @tmp2: element to be swapped with its next node
 * @list: pointer to head pointer of list
 * Return: nothing
 **/
void swap_list(listint_t *tmp, listint_t *tmp2, listint_t **list)
{
	listint_t *left, *right;

	left = tmp->prev;
	right = tmp2->next;
	if (left != NULL)
		left->next = tmp2;
	else
		*list = tmp2;
	if (right != NULL)
		right->prev = tmp;
	tmp2->prev = left;
	tmp->next = right;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	print_list(*list);
}
