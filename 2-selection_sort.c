#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: pointer
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, t, a = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		t = i;
		a = 1;
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[t])
				t = j, a = 0;
		}
		if (a == 0)
		{
			tmp = array[t];
			array[t] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
