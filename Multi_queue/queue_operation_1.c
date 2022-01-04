#include <stdio.h>
#include <stdlib.h>

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

void enqueue(queue *q, int *q_n, node *n_f)
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
	n->next = n_f;
	
	*q_n += 1;
}

void dequeue(queue *q, int *q_n, node *n_r)
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
	if (n_r != NULL)
		n_r->next = q->front;
	
	//Printing the dequed value
	printf("\n\nThe dequeued value is = %d\n\n", number);
	
	*q_n -= 1;
	
	//Reinitializing the queue
	if (*q_n == 0)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	
}

node *insert_begining(node *head)
{
	node *n;
	int num = 0;
	
	printf("Enter your value\n");
	scanf("%d", &num);
	
	n = (node *)malloc(sizeof(node));
	
	n->data = num;
	n->next = head;
	
	head = n;
	
	return head;
}


node *insert_end(node *head)
{
	node *n, *prev, *n_c;
	int num = 0;
	
	if (head == NULL)
	{
		head = insert_begining(head);
		return head;
	}
	
	printf("Enter your value\n");
	scanf("%d", &num);
	
	n = head;
	
	do
	{
		prev = n;
		n = n->next;
	}while(n != NULL);
	
	n_c = (node *)malloc(sizeof(node));
	
	n_c->data = num;
	n_c->next = NULL;
	
	prev->next = n_c;
	
	return n_c;
}

void display_list(node *head)
{
	node *n;
	n = head;
	//printf("%d", n->data);
	
	if (head == NULL)
	{
		printf("\n\nThe list is empty.\n\n");
		return;
	}
	
	printf("\n\nThe list is \n\n");
	do
	{
		printf("%d  ->  ", n->data);
		n = n->next;
	}while(n != NULL);
	
	printf("\n\n");
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
	while(n != q->rear)
	{
		printf("\t%d->", n->data);
		n = n->next;
	}
	
	printf("\t%d->", n->data);
	printf("\n\n");
	return;
}

int give_your_choice()
{
	int choice;
	printf("1-> Insert\n");
	printf("2-> Delete\n");
	printf("3-> Display queues\n");
	printf("4-> Display list\n");
	printf("0-> Exit\n");
	printf("\nEnter your choice\n");
	scanf("%d",&choice);
	return choice;
}

void main()
{
	node *head;
	queue *q1, *q2, *q3, *q4;
	int q11 = 5, q22 = 3, q33 = 2, q44 = 6;
	int choice = 1, i =0, count = 0;
	
	head = NULL;
	
	//Initializing the queue parameters
	q1 = (queue *)malloc(sizeof(queue));
	q1->rear = NULL;
	q1->front = NULL;
	q11 = 5;
	
	q2 = (queue *)malloc(sizeof(queue));
	q2->rear = NULL;
	q2->front = NULL;
	q22 = 3;
	
	q3 = (queue *)malloc(sizeof(queue));
	q3->rear = NULL;
	q3->front = NULL;
	q33 = 2;
	
	q4 = (queue *)malloc(sizeof(queue));
	q4->rear = NULL;
	q4->front = NULL;
	q44 = 6;
	
	for (i = 0; i<16; i++)
	{
		if (i < 5)
		{
			if (i == 0)
			{
				head = insert_end(head);
				q1->front = head;
				q1->rear = head;
				continue;
			}
			
			q1->rear = insert_end(head);
		}
		
		else if (i >= 5 && i < 8)
		{
			if (i == 5)
			{
				q2->front = insert_end(head);
				q2->rear = q2->front;
				continue;
			}
			
			q2->rear = insert_end(head);
		}
		
		else if (i >= 8 && i < 10)
		{
			if (i == 8)
			{
				q3->front = insert_end(head);
				q3->rear = q3->front;
				continue;
			}
			
			q3->rear = insert_end(head);
		}
		
		else if (i >= 10 && i < 16)
		{
			if (i == 10)
			{
				q4->front = insert_end(head);
				q4->rear = q4->front;
				continue;
			}
			
			q4->rear = insert_end(head);
		}
	}
	
	display_list(head);
	
	display(q1);
	display(q2);
	display(q3);
	display(q4);
	
	while (choice != 0)
	{
		choice = give_your_choice();
		
		if(choice == 1)
		{
			if ((q11 <= q22) && (q11 <= q33) && (q11 <= q44))
			{
				if (q1->front == NULL)
				{	
					enqueue(q1, &q11, q2->front);
					head = q1->front;
				}
				
				else
					enqueue(q1, &q11, q2->front);
			}
			
			else if ((q22 <= q11) && (q22 <= q33) && (q22 <= q44))
			{
				if (q2->front == NULL)
				{
					enqueue(q2, &q22, q3->front);
					q1->rear->next = q2->front;
				}
				
				else
					enqueue(q2, &q22, q3->front);
			}
				
			else if ((q33 <= q11) && (q33 <= q22) && (q33 <= q44))
			{
				if (q3->front == NULL)
				{
					enqueue(q3, &q33, q4->front);
					q2->rear->next = q3->front;
				}
				
				else
					enqueue(q3, &q33, q4->front);
			}
			
			else
			{
				if (q4->front == NULL)
				{
					enqueue(q4, &q44, NULL);
					q3->rear->next = q4->front;
				}
				
				else
					enqueue(q4, &q44, NULL);
			}
		}
		
		else if(choice == 2)
		{
			if ((q11 >= q22) && (q11 >= q33) && (q11 >= q44))
			{
				dequeue(q1, &q11, NULL);
				
				if (q1->front != NULL)
					head = q1->front;
				
				else
					head = q2->front;
			}
			
			else if ((q22 >= q11) && (q22 >= q33) && (q22 >= q44))
			{
				dequeue(q2, &q22, q1->rear);
				
				if (q2->front == NULL)
					head = q3->front;
			}
				
			else if ((q33 >= q11) && (q33 >= q22) && (q33 >= q44))
			{
				dequeue(q3, &q33, q2->rear);
				
				if (q3->front == NULL)
					head = q4->front;
			}
			
			else
			{	
				dequeue(q4, &q44, q3->rear);
				
				if (q4->front == NULL)
					head = NULL;
			}
		}
		
		else if (choice == 3)
		{
			display(q1);
			display(q2);
			display(q3);
			display(q4);
			
			printf("q11 = %d\t q22 = %d\t q33 = %d\t q44 = %d\n\n", q11, q22, q33, q44);
		}
		
		else if (choice == 4)
		{
			display_list(head);
		}
		
		else if (choice == 0)
		{
			printf("THANK YOU !!!\n\n");
			return;
		}
		
		else
			printf("\n\nPlease provide a correct input\n\n");
	}
}
