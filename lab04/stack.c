#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

int array[SIZE], top;
void display(int*);
void push(int*, int);
int pop(int*);

void stack() {
	top = -1;
	int choice, value;

	printf("Stack Operations:\n\t1: display\n\t2: insert (PUSH)\n\t3: remove (POP)\n\t4: Exit\n");
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
	if (top == -1)
	{
		printf("Stack is empty.\n");
		return;
	}

	printf("%d <-- TOP\n", array[top]);
	int i = top - 1;
	for (; i >= 0; i--)
		printf("%d\n", array[i]);
}


void push(int* array, int item)
{
	if (top == SIZE- 1)
	{
		printf("OVERFLOW ALERT!!! Stack is full.\n");
		return;
	}
	array[++top] = item;
}


int	pop(int* array)
{
	if (top == -1)
	{
		printf("UNDERFLOW ALERT!!! Stack is empty.\n");
		return;
	}

	int deletedItem = array[top--];
	return deletedItem;
}