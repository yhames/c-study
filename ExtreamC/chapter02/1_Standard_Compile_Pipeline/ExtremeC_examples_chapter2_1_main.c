#include <stdio.h>
#include "ExtremeC_examples_chapter2_1.h"

int	main(int argc, char **argv)
{
	int		array[5];
	double	average;

	array[0] = 10;
	array[1] = 3;
	array[2] = 5;
	array[3] = -8;
	array[4] = 9;
	average = avg(array, 5, NORMAL);
	printf("The average: %f\n", average);
	average = avg(array, 5, SQUARED);
	printf("The squared average: %f\n", average);
	return (0);
}
