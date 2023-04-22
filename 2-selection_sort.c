#include "sort.h"


/**
 * selection_sort - sorts an array by selection sort
 * @array: the array to be sorted
 * @size: the size of the arrary
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, min;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}

