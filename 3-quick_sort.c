#include "sort.h"

/**
 * swap - swaps two elements in array
 * @a: first element
 * @b: second element
 * @arr: the array
 * @size: the size of the array
 */
void swap(int *a, int *b, int *arr, size_t size)
{
	int tmp = *a;

	if (*a != *b)
	{
		*a = *b;
		*b = tmp;
		print_array(arr, size);
	}
}

/**
 * partition - the partioning algorithm used in quick sort
 * @arr: the array to be sorted
 * @l: the left hand side
 * @h: the right hand side
 * @size: the size of the array
 * Return: returns the right site of the pivot
 */

int partition(int *arr, int l, int h, size_t size)
{
	int piv, i, j;

	piv = arr[h];
	i = l - 1;

	for (j = l; j < h; j++)
	{
		if (arr[j] <= piv)
		{
			i++;
			swap(&arr[i], &arr[j], arr, size);
		}
	}

	swap(&arr[i + 1], &arr[h], arr, size);
	return (i + 1);

}


/**
 * sort - sorts the array by quick sort algorithm
 * @arr: the array to be sorted
 * @l: the left hand side
 * @h: the right hadn side
 * @size: the size of the array
 */
void sort(int *arr, int l, int h, size_t size)
{
	int j;

	if (l < h)
	{
		j = partition(arr, l, h, size);
		sort(arr, l, j - 1, size);
		sort(arr, j + 1, h, size);
	}
}

/**
 * quick_sort - sorts the array be quick sort algorithm using sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	sort(array, 0, size - 1, size);
}
