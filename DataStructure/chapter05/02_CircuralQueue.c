#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int	t_element;
typedef struct s_cQueue
{
	int			front;
	int			rear;
	t_element	data[MAX_QUEUE_SIZE];
}	t_cQueue;

void	init_queue(t_cQueue *q)
{
	q->front = 0;
	q->rear = 0;
}

void	enqueue(t_cQueue *q, int item)
{
	if (((q->rear) + 1) % MAX_QUEUE_SIZE == q->front)
	{
		fprintf(stderr, "Queue overflow error\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

t_element	dequeue(t_cQueue *q)
{
	if (q->front == q->rear)
	{
		fprintf(stderr, "Queue is empty\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return (q->data[q->front]);
}

t_element	peek(t_cQueue *q)
{
	if (q->front == q->rear)
	{
		fprintf(stderr, "Queue is empty\n");
		exit(1);
	}
	return (q->data[q->front]);
}

int	main(void)
{
	t_cQueue	q;

	init_queue(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	dequeue(&q);
	enqueue(&q, 50);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	return (0);
}
