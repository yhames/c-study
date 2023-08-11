#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int	t_element;
typedef struct s_queue
{
	int			front;
	int			rear;
	t_element	data[MAX_QUEUE_SIZE];
}	t_queue;

void	init_queue(t_queue *q)
{
	q->rear = -1;
	q->front = -1;
}

void	enqueue(t_queue *q, int item)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
	{
		fprintf(stderr, "%s\n", "Queue overflow error\n");
		exit(1);
	}
	q->data[++(q->rear)] = item;
}

t_element	dequeue(t_queue *q)
{
	if (q->front == q->rear)
	{
		fprintf(stderr, "%s\n", "Queue is empty\n");
		exit(1);
	}
	return (q->data[++(q->front)]);
}

int	main(void)
{
	int		item;
	t_queue	q;

	init_queue(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	printf("%d\n", dequeue(&q));
	enqueue(&q, 60);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	return (0);
}
