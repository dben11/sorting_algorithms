#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: the given array
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	int in = 0, out = 0, range = 1, tmp = 0;

	if (!array || (int) size < 2)
		return;

	while (range < (int) size / 3)
		range = range * 3 + 1;

	while (range > 0)
	{
		out = range;
		while (out < (int) size)
		{
			tmp = array[out];
			in = out;

			while (in > range - 1 && array[in - range] >= tmp)
			{
				array[in] = array[in - range];
				in = in - range;
			}
			array[in] = tmp;
			out++;
		}
		print_array(array, size);
		range = (range - 1) / 3;
	}
}
