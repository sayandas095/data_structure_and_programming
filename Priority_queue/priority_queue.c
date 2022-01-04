#include <stdio.h>
#include <stdlib.h>

//Defining structure
typedef struct queue
{
	struct node
	{
		char *name;
		int gate_sc;
		struct node *next;
	}*rear, *front;
}queue;

typedef struct node node;

void enqueue(queue *q)
{
	int number;
	char *na;
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
	
	na = (char *)malloc(sizeof(char));
	
	//Taking the data from the user
	printf("\n\nEnter the name\n");
	scanf("%s", na);
	printf("\n\nEnter the gate score\n");
	scanf("%d", &number);
	
	//Puting the data in the queue
	q->rear = n;
	n->name = (char *)malloc(sizeof(char));
	n->name = na;
	n->gate_sc = number;
	n->next = NULL;
	
}

void dequeue(queue *q)
{
	node *highest, *n, *prev, *prev_h;
	int number;
	char *na;
	
	//checking for underflow condition
	if (q->rear == NULL && q->front == NULL)
	{
		printf("\n\nUnderflow\n\n");
		return;
	}
	
	n = q->front;
	highest = n;
	
	while (n != NULL)
	{
	
		if (n->gate_sc > highest->gate_sc)
		{
			highest = n;
			prev_h = prev;
		}
		
		prev = n;
		n= n->next;
	}
	
	if (highest == q->front)
	{
		na = (char *)malloc(sizeof(char));
		na = q->front->name;
		number = q->front->gate_sc;
		q->front = q->front->next;
		
		printf("\n\nThe dequeued value is :- \nName = %s\nGate score = %d\n\n", na, number);
	}
	
	else
	{
		na = (char *)malloc(sizeof(char));
		na = highest->name;
		number = highest->gate_sc;
		
		prev_h->next = highest->next;
		
		if (highest == q->rear)
		{
			//printf("Entered\n");
			q->rear = prev_h;
		}
			
		printf("\n\nThe dequeued value is :- \nName = %s\nGate score = %d\n\n", na, number);
	}
	
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
	
	if (q->front == NULL && q->rear == NULL)
	{
		printf("\n\nSorry your list is empty\n\n");
		return;
	}
	
	printf("\n\nThe queue list is");
	while(n != NULL)
	{
		printf("\t%s %d->", n->name, n->gate_sc);
		n = n->next;
	}
	
	printf("\n\n");
	return;
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
	
	//Initializing the queue parameters
	q = (queue *)malloc(sizeof(queue));
	q->rear = NULL;
	q->front = NULL;
	
	while (choice != 0)
	{
		choice = give_your_choice();
		
		if (choice == 1)
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
			printf("\n\nTHANK YOU!!!\n\n");
		}
		
		else
		{
			printf("\n\nPlease give the right option\n\n");
		}
	}
}
