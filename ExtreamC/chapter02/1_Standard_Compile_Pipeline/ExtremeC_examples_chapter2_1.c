#include "ExtremeC_examples_chapter2_1.h"

double	avg(int *array, int length, average_type_t type)
{
	int		i;
	double	sum;

	if (length <= 0 || type == NONE)
	{
		return (0);
	}
	sum = 0.0;
	i = 0;
	while (i < length)
	{
		if (type == NORMAL)
		{
			sum += array[i];
		}
		else if (type == SQUARED)
		{
			sum += array[i] * array[i];
		}
		i++;
	}
	return (sum / length);
}
