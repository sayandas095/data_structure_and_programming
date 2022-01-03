#include <stdio.h>
#include<stdlib.h>
#include <string.h>
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
	char *c;
	
	c = (char *)malloc(sizeof(char));
	
	printf("Enter your value (0 / 1)\n");
	scanf("%s", c);
	
	if(strlen(c) > 1)
	{
		printf("\nPlease give a proper input\n");
		return head;
	}
	
	else if(c[0] == 48 || c[0] == 49)
	{
		n = (node *)malloc(sizeof(node));
		
		num = atoi(c);
		
		n->data = num;
		n->next = head;
	
		head = n;
		
		return head;
	}
	
	else
	{
		printf("\nPlease give a proper input\n");
		return head;
	}
}

void display(node *head)
{
	node *n;
	n = head;
	//printf("%d", n->data);
	
	if(n == NULL)
		return;
		
	printf("\n\nThe list is \n\n");
	do
	{
		printf("%d  ->  ", n->data);
		n = n->next;
	}while(n != NULL);
	
	printf("\n\n");
}

int length_list(node *head)
{
	int len = 0;
	node *n;
	n = head;
	
	while(n != NULL)
	{
		len = len + 1;
		n = n->next;
	}
	
	return len;
}

int decimal_value_calculation(node *head)
{
	int len = 0, i = 0, sum = 0;
	node *n;
	
	n = head;
	
	len = length_list(head);
	
	for (i = (len - 1) ; i >= 0; i--)
	{
		sum = sum + (pow(2, i) * n->data);
		
		n = n->next;
	}
	
	return sum;
}

int main()
{
	node *head;
	char *choice;
	int dec_value = 0;
	
	//Initializing the linked list
	head = NULL;
	
	do
	{
		choice = (char *)malloc(sizeof(char));
		
		printf("\n\n1-> To enter a value in the list\n");
		printf("0-> Exit\n");
		printf("Enter your choice \n");
		scanf("%s", choice);
		
		if(choice[0] == 48)
			break;
		else if(choice[0] == 49 && strlen(choice) == 1)
		{
			head = insert_begining(head);
			display(head);
		}
				
	}while (1);
	
	//Converting the list into equivalent decimal number
	dec_value = decimal_value_calculation(head);	
	
	printf("\n\nThe decimal value of the above binary number is = %d\n\n", dec_value);
	
	return 0;
}
