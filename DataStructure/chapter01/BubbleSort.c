#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubbleSort(int* arr, int arr_size)
{
	int i, j, tmp;
	int count;

	for(i = arr_size - 1; i > 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			count++;
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
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
			count += bubbleSort(arr, i);
		}
		avg = count / iter;
		expected = (i * (i+1)) / 2;
		printf("N=%d time-complextiry : expected = %d, actual = %d\n", i, expected, avg);
	}

	return 0;
}
