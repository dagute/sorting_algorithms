#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
void quick_sort_hoare(int *array, size_t size);
int part_hoare(int *array, int beg, int end, size_t size);
void counting_sort(int *array, size_t size);
void swap_list(listint_t *tmp, listint_t *tmp2, listint_t **list);
size_t list_size(listint_t *list);
void cocktail_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void swap(int *a, int *b);
void quick_sort2(int *array, int beg, int end, size_t size);
int part(int *array, int beg, int end, size_t size);
void quick_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void counting_sort(int *array, size_t size);
#endif
