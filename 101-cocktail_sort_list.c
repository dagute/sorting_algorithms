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
	size_t size;
	int s = 1;

	size = list_size(*list);
	if (size < 2)
		return;

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
 * list_size - returns the size of a linked list
 * @list: linked list
 * Return: returns the size of a list
 */
size_t list_size(listint_t *list)
{
	size_t size;
	listint_t *aux;

	aux = list;

	for (size = 0; aux != NULL; ++size)
	{
		aux = aux->next;
	}
	return (size);
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
