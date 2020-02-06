#include "sort.h"
/**
 * quick_sort2 - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: pointer
 * @beg: beginning of the array
 * @end: end of the array
 * @size: size
 * Return: nothing
 */
void quick_sort2(int *array, int beg, int end, size_t size)
{
	int pos;

	if (beg < end)
	{
		pos = part_hoare(array, beg, end, size);
		quick_sort2(array, beg, pos - 1, size);
		quick_sort2(array, pos, end, size);
	}
}
/**
 * part_hoare - rearrange the array
 * @array: array
 * @beg: beginning of the array
 * @end: end of the array
 * @size: size
 * Return: index
 */
int part_hoare(int *array, int beg, int end, size_t size)
{
	int j = end;
	int pivot = array[end];
	int i = beg - 1;

	if (array[i] == pivot && array[j] == pivot)
		return (0);

	do {
		i++;
		while (array[i] < pivot)
		{
			i++;
		}
		while (array[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	} while (i < j);
	return (i);
}
/**
 * swap - swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array
 * @size: size of the array
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort2(array, 0, size - 1, size);
}
