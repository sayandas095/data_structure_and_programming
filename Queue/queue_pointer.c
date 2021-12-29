#include<stdio.h>
#include<stdlib.h>

//Defining structure
typedef struct queue
{
	struct node
	{
		int data;
		struct node *next;
	}*rear, *front;
}queue;

typedef struct node node;

void enqueue(queue *q)
{
	int number;
	node *n;
	n = (node *)malloc(sizeof(node));
	if (n == NULL)
	{
		printf("\n\nOverflow\n\n");
		return;
	}
	
	//For the first entry in the queue
	if (q->rear == NULL && q->front == NULL)
	{
		q->front = n;
	}
	else
	{
		q->rear->next = n;
	}
	
	//Taking the data from the user
	printf("\n\nEnter a number\n");
	scanf("%d", &number);
	
	//Puting the data in the queue
	q->rear = n;
	n->data = number;
	n->next = NULL;
}

void dequeue(queue *q)
{
	int number;
	//checking for underflow condition
	if (q->rear == NULL && q->front == NULL)
	{
		printf("\n\nUnderflow\n\n");
		return;
	}
	
	//dequeue
	number = q->front->data;
	q->front = q->front->next;
	
	//Printing the dequed value
	printf("\n\nThe dequeued value is = %d\n\n", number);
	
	//Reinitializing the queue
	if (q->front == NULL)
	{
		q->front = NULL;
		q->rear = NULL;
	}
}

void display(queue *q)
{
	node *n;
	
	n = q->front;
	
	if (n == NULL)
	{
		printf("\nThe queue is empty\n\n\n");
		return;
	}
	
	printf("\nThe queue is :-\n");
	while (n != NULL)
	{
		printf("%d\t", n->data);
		n = n->next;
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
	queue *q;
	int choice = 1;
	q = (queue *)malloc(sizeof(queue));
	q->rear = NULL;
	q->front = NULL;
	
	while(choice != 0)
	{
		choice = give_your_choice();
		if(choice == 1)
		{
			enqueue(q);
		}
		
		else if (choice == 2)
		{
			dequeue(q);
		}
		
		else if (choice == 3)
		{
			display(q);
		}
		
		else if (choice == 0)
		{
			printf("\n\nThank you!!!\n\n");
		}
	}
}
