#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: pointer to array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, temp = 0, max = 0, swapped = 0;

	if (!array || size < 2)
		return;

	max = size - 1;

	for (i = 0; i < max; ++i)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			swapped = 1;
			print_array(array, size);
		}
		if (swapped == 1 && i == max - 1)
			i = -1, swapped = 0, --max;
	}
}
