#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int t_element;
typedef struct s_deque
{
	int 		front;
	int 		rear;
	t_element	data[MAX_QUEUE_SIZE];
}	t_deque;

void	init_deque(t_deque *q)
{
	// q->front = q->rear = 0;
}

void	add_front(t_deque *q, t_element item)
{
	// front - 1 % MAX_QUEUE_SIZE 자리에 item 추가
}

void	add_rear(t_deque *q, t_element item)
{
	// rear + 1 % MAX_QUEUE_SIZE 자리에 item 추가
}

t_element	del_front(t_deque *q)
{
	// front = front + 1 % MAX_QUEUE_SIZE
	// front + 1 % MAX_QUEUE_SIZE 자리의 item 반환
}

t_element	del_rear(t_deque *q)
{
	// rear 자리의 item 반환
	// rear = rear - 1 % MAX_QUEUE_SIZE
}

t_element	get_front(t_deque *q)
{
	// front 자리의 item 반환
}

t_element	get_rear(t_deque *q)
{
	// rear 자리의 item 반환
}

int main()
{
	// Deque 테스트
	return 0;
}


