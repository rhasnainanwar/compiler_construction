#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

int array[SIZE], rear, front;
void display(int*);
void push(int*, int);
int pop(int*);

void queue() {
	rear = front = -1;
	int choice, value;

	printf("Queue Operations:\n\t1: display\n\t2: insert (PUSH)\n\t3: remove (POP)\n\t4: Exit\n");
	while (1)
	{
		printf("\n> ");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			display(array);
			break;
		case 2:
			printf("Enter item to be inserted: ");
			scanf("%d", &value);
			push(array, value);
			break;
		case 3:
			value = pop(array);
			printf("Value popped: %d\n", value);
			break;
		case 4:
			exit(0);
		default:
			printf("\nInvalid choice.\n");
			break;
		}
	}
}


void display(int* array)
{
	if (front == -1)
	{
		printf("Queue is empty.\n");
		return;
	}

	int i = front+1;

	printf("%d <-- FRONT\n", array[front]);
	for (; i < rear; i++)
		printf("%d\n", array[i]);
	if(front != rear)
		printf("%d <-- REAR\n", array[rear]);
}


void push(int* array, int item)
{
	if (rear == SIZE- 1)
	{
		printf("OVERFLOW ALERT!!! Queue is full.\n");
		return;
	}
	
	if(front == -1)
		front = 0;
	array[++rear] = item;
}


int	pop(int* array)
{
	if (front == -1 || front > rear)
	{
		printf("UNDERFLOW ALERT!!! Queue is empty.\n");
		return;
	}

	int deletedItem = array[front++];
	return deletedItem;
}