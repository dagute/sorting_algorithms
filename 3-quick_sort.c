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
		pos = part(array, beg, end, size);
		quick_sort2(array, beg, pos - 1, size);
		quick_sort2(array, pos + 1, end, size);
	}
}
/**
 * part - rearrange the array
 * @array: array
 * @beg: beginning of the array
 * @end: end of the array
 * @size: size
 * Return: index
 */
int part(int *array, int beg, int end, size_t size)
{
	int j;
	int pivot = array[end];
	int i = beg - 1;

	for (j = beg; j <= end - 1; j++)
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
	if ((i + 1) != end)
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
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
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort2(array, 0, size - 1, size);
}
