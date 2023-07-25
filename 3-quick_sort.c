#include "sort.h"

/**
 *quick_sort - Sorts an array of integers in ascending order using
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}

/**
 * lomuto_qsort - Sort an array of integers using the Lomuto partition scheme.
 *
 * @array: The array to be sorted.
 * @lo: The first element in the array.
 * @hi: The last element in the array.
 * @size: The size of the array.
 */
void lomuto_qsort(int *array, int lo, int hi, size_t size)
{
	int p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		lomuto_qsort(array, lo, p - 1, size);
		lomuto_qsort(array, p + 1, hi, size);
	}
}

/**
 * partition - Divide the array using the Lomuto partition scheme.
 *
 * @array: The array to be partitioned.
 * @lo: The first element of the array.
 * @hi: The last element in the array.
 * @size: The size of the array.
 *
 * Return: The index of the array from where the check should begin.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1, j, tmp;

	for (j = lo; j <= hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	return (i);
}

