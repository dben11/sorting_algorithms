#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: pointer to array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * swap - swap two integerrs in an array
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - order a subset of an array of integers according to
 * the lomuto partition scheme (last element as pivot)
 *
 * @array: the array of integers
 * @size: the size of the array
 * @left: the starting index of the subset to order
 * @right: the ending index of the subset to order
 *
 * Return: the final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = &array[right];
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(&array[below], &array[above]);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap(&array[above], pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - sort an array of integers in ascending
 * order using the quicksort algorithm
 * @array: the given to work with
 * @size: the size of the array
 * @left: the starting index of the array partion to order
 * @right: The ending index of the array patition to order
 *
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}
