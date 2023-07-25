#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *                  Selection Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_el_idx, temp;
	int flag = 0;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min_el_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_el_idx])
			{
				min_el_idx = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			temp = array[i];
			array[i] = array[min_el_idx];
			array[min_el_idx] = temp;
			print_array(array, size);
		}
		flag = 0;
	}
}

