#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;

element stack[MAX_STACK_SIZE];
int top = -1;

int is_full()
{
	return top == MAX_STACK_SIZE - 1;
}

int is_empty()
{
	return top == -1;
}

void push(element item)
{
	if(is_full())
	{
		fprintf(stderr, "stack overflow error\n");
		return;
	}

	stack[++top] = item;
}

element pop()
{
	if(is_empty())
	{
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}

	return stack[top--];
}

element peek()
{
	if(is_empty())
	{
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}

	return stack[top];
}

int main(void)
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}
