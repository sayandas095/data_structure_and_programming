#include<stdio.h>
#define SIZE 5

typedef int datatype;

//defining structure
typedef struct queue
{
	int rear;
	int front;
	datatype item[SIZE];
}queue;

void enqueue(queue *q)
{
	datatype n;
	//checking overflow condition
	if (q->rear == (SIZE - 1))
	{
		printf("\n\nOverflow \n\n");
		return;
	}
	
	//Accepting a number 
	printf("\nEnter a number \n");
	scanf("%d", &n);
	
	if (q->rear == -1 && q->front == -1)
	{
		q->front = 0;
	}
	
	//placing the value in the cell
	q->rear += 1;
	q->item[q->rear] = n;
}

void dequeue(queue *q)
{
	datatype n;
	//checking for underflow
	if (q->front == -1 && q->rear == -1)
	{
		printf("\n\nUnderflow\n\n");
		return;
	}
	
	//geting the value
	n = q->item[q->front];
	q->front += 1;
	printf("\nThe dequeued value is = %d\n\n", n);
	
	//Reinitializing
	if (q->front == (q->rear + 1))
	{
		q->front = -1;
		q->rear = -1;
	}
}

void display(queue *q)
{
	int i = 0;
	
	if (q->front == -1)
	{
		printf("The list is empty \n");
		return;
	}
	
	printf("\nThe queue looks like :-\n");
	
	for (i = q->front; i<=q->rear; i++)
	{
		printf("%d\t", q->item[i]);
	}
	printf("\n\n");
}

int give_your_choice()
{
	int choice;
	printf("1-> Enqueue\n");
	printf("2-> Dequeue\n");
	printf("3-> Display\n");
	printf("0-> Exit\n");
	printf("\nEnter your choice\n");
	scanf("%d",&choice);
	return choice;
}

void main()
{
	queue q;
	q.rear = -1;
	q.front = -1;
	int choice = 1;
	while(choice != 0)
	{
		choice = give_your_choice();
		if(1 == choice)
		{
			enqueue(&q);
		}
		
		else if (2 == choice)
		{
			dequeue(&q);
		}
		
		else if (3 == choice)
		{
			display(&q);
		}
		
		else if (0 == choice)
		{
			printf("\n\nThank you!!!\n\n");
		}
	}
}
