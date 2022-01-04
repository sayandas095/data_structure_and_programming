#include <stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct node node;

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

node *insert_end(node *head, int *length)
{
	node *n, *prev, *n_c;
	int num = 0;
	
	n = head;
	
	if (n == NULL)
	{
		head = insert_begining(head);
		*length += 1;
		
		return head;
	}
	
	do
	{
		prev = n;
		n = n->next;
	}while(n != NULL && n != head);
	
	printf("Enter your value\n");
	scanf("%d", &num);
	
	n_c = (node *)malloc(sizeof(node));
	
	n_c->data = num;
	n_c->next = head;
	
	prev->next = n_c;
	
	*length += 1;
	
	return head;
}

void display(node *head)
{
	node *n;
	n = head;
	//printf("%d", n->data);
	printf("\n\nThe list is \n\n");
	do
	{
		printf("%d  ->  ", n->data);
		n = n->next;
	}while(n != NULL && n != head);
	
	printf("\n\n");
}

void display_list(node *head, int length)
{
	node *n, *first_node, *prev;
	
	int length_1, length_2;
	int i, j;
	
	n = head;
	
	length_1 = (int)ceil((double)length / 2.0);
	//printf("length 1 = %d\n", length_1);
	//length_2 = length / 2;
	
	for (j = 0; j<2; j++)
	{
		printf("\nThe list %d is ", (j + 1));
	
		for (i = 0;i<length_1 && (n != head || j == 0); i++)
		{
			if (i == 0)
				first_node = n;
			
			prev = n;
			printf("\t%d", n->data);
			n = n->next;
		}
			
		prev->next = first_node;
		printf("\n\n");
	}
	
}

int give_choice()
{
	int choice = 0;
	
	printf("\n1 -> Insert");
	printf("\n2 -> Display");
	printf("\n0 -> Exit");
	printf("\nEnter your choice\n");
	scanf("%d", &choice);
	return choice;
}

void main()
{
	node *head;
	int choice = 1;
	int length = 0;
	
	//Initializing the linked list
	head = NULL;
	
	while(choice != 0)
	{
		choice = give_choice();
		if (choice == 1)
		{
			head = insert_end(head, &length);
		}
		
		else if (choice == 2)
		{
			display(head);
			printf("\n\nThe length is = %d\n\n", length);
		}
		
		else if (choice == 0)
		{
			break;
		}
		
		else
			printf("\n\nPlease enter the right option\n\n");
	}
	
	display_list(head, length);
}
