#include <stdio.h>	// printf 함수를 위한 헤더
#include <stdlib.h>	// Heap 메모리를 위한 헤더

#define QUEUE_MAX_SIZE 100

typedef struct queue_s{
	int		front;
	int		rear;
	double	*arr;
}	t_queue;

void	init(t_queue *q)
{
	q->front = 0;
	q->rear = 0;
	q->arr = (double *)malloc(QUEUE_MAX_SIZE * sizeof(double));	// 이제 이건 제껍니다 by queue 객체
}

void	destroy(t_queue *q)
{
	free(q->arr);	// 큐 안에 arr의 힙 메모리는 q에서 해제
}

int	size(t_queue *q)
{
	return (q->rear - q->front);
}

void	enqueue(t_queue *q, double item)
{
	q->arr[q->rear] = item;
	q->rear++;
}

double	dequeue(t_queue *q)
{
	double	item;

	item = q->arr[q->front];
	q->front++;
	return (item);
}

int	main(int argc, char **argv)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));	// 이제 이건 제껍니다 by main 함수
	init(q);
	enqueue(q, 6.5);
	enqueue(q, 1.3);
	enqueue(q, 2.4);
	printf("%f\n", dequeue(q));
	printf("%f\n", dequeue(q));
	printf("%f\n", dequeue(q));
	destroy(q);
	free(q);	// 큐 객체의 힙 메모리는 main에서 해제
	return (0);
}
