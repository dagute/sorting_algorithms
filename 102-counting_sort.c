#include "sort.h"
/**
 * counting_sort - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @array: double pointer to list
 * @size: the size of array
 * Return: nothng
 */
void counting_sort(int *array, size_t size)
{
	int min = array[0], max = array[0], i;
	int *postions, *sum, *total, *cop;

	cop = malloc(size * 4);
	for (i = 0; i < size; i++)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
		cop[i] = array[i];
	}
	postions = malloc((max + 1) * 4);
	sum = malloc((max + 1) * 4);
	for (i = 0; i < size; i++)
	{
		postions[array[i]]++;
	}
	print_array(postions, max + 1);
	sum[0] = postions[0];
	for (i = 1; i < max + 1; i++)
	{
		sum[i] = sum[i - 1] + postions[i];
	}
	total = malloc((size - 1) * 4);
	for (i = 0; i < size; i++)
	{
		array[]
	}
}
