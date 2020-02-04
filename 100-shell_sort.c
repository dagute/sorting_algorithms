#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 * @array: array
 * @size: size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int a;
	size_t i, tmp, t, gap = 1;

	if (array == NULL || size < 2)
		return;
	while (gap <= size / 3)
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		for (i = 0; i < size - gap; i++)
		{
			a = 0;
			if (array[i] > array[gap + i])
			{
				a = 1;
				tmp = array[i];
				array[i] = array[gap + i];
				array[gap + i] = tmp;
			}
			t = i;
			while (a == 1 && array[t - gap] > array[t] && t >= gap)

			{
				tmp = array[t - gap];
				array[t - gap] = array[t];
				array[t] = tmp;
				t = t - gap;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
