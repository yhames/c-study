#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selectionSort(int* arr, int arr_size)
{
	int i, j, minIndex, tmp;
	int count;

	for (i = 0; i < arr_size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < arr_size; j++)
		{
			count++;
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		tmp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = tmp;
	}
	return count;
}

void init(int* arr, int arr_size)
{
	int i;

	srand(clock());
	for (i = 0; i < arr_size; i++)
	{
		arr[i] = rand();
	}
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("./a.out [number of iterations]\n");
		exit(0);
	}
	const int iter = atoi(argv[1]);

	int i, j;
	int avg, expected;
	long count;
	
	for (i=10; i<100; i+=10)
	{
		count = 0;
		for (j=0; j < iter; j++)
		{
			int arr[i];
			init(arr, i);
			count += selectionSort(arr, i);
		}
		avg = count / iter;
		expected = (i * (i+1)) / 2;
		printf("N=%d time-complextiry : expected = %d, actual = %d\n", i, expected, avg);
	}

	return 0;
}
