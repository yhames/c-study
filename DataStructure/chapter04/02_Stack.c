#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct element	// here
{
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
} element;

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
	element ie = {20231052, "Park", "Seoul"};
	push(ie);
	element oe = pop();

	printf("%d\n", oe.student_no);
	printf("%s\n", oe.name);
	printf("%s\n", oe.address);
}
