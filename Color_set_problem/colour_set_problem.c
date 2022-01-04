#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define NUMBER_OF_SET 5

//Defining structure
typedef struct info
{
	char *c1;
	char *c2;
	char *c3;
	struct info *next;
}info;

info *insert_node(info *head)
{
	info *n, *n_c, *prev;
	
	n = head;
	
	if(n == NULL)
	{
		n_c = (info *)malloc(sizeof(info));
		
		n_c->c1 = (char *)malloc(sizeof(char));
		printf("Please input the first colour\n");
		scanf("%s", n_c->c1);
	
		n_c->c2 = (char *)malloc(sizeof(char));
		printf("Please input the second colour\n");
		scanf("%s", n_c->c2);
	
		n_c->c3 = (char *)malloc(sizeof(char));
		printf("Please input the third colour\n");
		scanf("%s", n_c->c3);
		
		n_c->next = NULL;
		
		head = n_c;
		
		return head;
	}
	
	while(n->next != NULL)
	{
		prev = n;
		n = n->next;
	}
	
	n_c = (info *)malloc(sizeof(info));
		
	n_c->c1 = (char *)malloc(sizeof(char));
	printf("Please input the first colour\n");
	scanf("%s", n_c->c1);
	
	//Checking the sequence if it is matching or not
	if (strcmp(n->c3, n_c->c1) != 0)
	{
		printf("\nSorry sequence is not maintained\n");
		exit(1);
	}

	n_c->c2 = (char *)malloc(sizeof(char));
	printf("Please input the second colour\n");
	scanf("%s", n_c->c2);

	n_c->c3 = (char *)malloc(sizeof(char));
	printf("Please input the third colour\n");
	scanf("%s", n_c->c3);
	
	n_c->next = NULL;
	
	n->next = n_c;
	
	return head;
}

int is_valid(info *head)
{
	info *n;
	
	n = head;
	
	while(n != NULL)
	{
		if(n->next != NULL)
		{
			if(strcmp(n->c3, n->next->c1) != 0)
			{
				//printf("Entered here\n");
				return FALSE;
			}
			
			n = n->next;
		}
		
		else
		{
			break;
		}
		
	}
	
	if(strcmp(n->c3, head->c1) != 0)
	{
		//printf("Entered here_1\n");
		return FALSE;
	}
	
	else
		return TRUE;
}

info *exchange_between_first_last(info *head)
{
	info *n, *head_pos;
	char *c;
	
	n = head;
	//head_pos = head;
	
	n->c1 = "color";
	
	while(n->next != NULL)
	{
		n = n->next;
	}
	
	/*c = (char *)malloc(sizeof(char));
	
	strcpy(c, head_pos->c1);
	strcpy(head_pos->c1, n->c1);
	strcpy(n->c1, c);
	
	c = (char *)malloc(sizeof(char));
	
	strcpy(c, head_pos->c2);
	strcpy(head_pos->c2, n->c2);
	strcpy(n->c2, c);
	
	c = (char *)malloc(sizeof(char));
	
	strcpy(c, head_pos->c3);
	strcpy(head_pos->c3, n->c3);
	strcpy(n->c3, c);*/
	
	n->c1 = "color";
	
	return n;
}

void disp_second_string_values(info *head)
{
	//printf("\n%p\n", head);
	info *n;
	
	n = head;
	
	printf("\n\nThe second string set is \n");
	while(n!=NULL)
	{
		printf("%s\t", n->c2);
		n = n->next;
	}
}

void display(info *head)
{
	info *n;
	int index = 1;
	
	n = head;
	while(n != NULL)
	{
		printf("%d. %s\t%s\t%s\n", index, n->c1, n->c2, n->c3);
		n = n->next;
		index += 1;
	}
}

void main()
{
	info *head, *end_node;
	int i = 0, result = 0, choice = 1;
	
	head = NULL;
	
	//taking input from the user
	while(choice != 0)
	{
		head = insert_node(head);
		printf("\nDo you want to insert any more node (if yes press 1 or else press 0 to exit)\n");
		scanf("%d", &choice);
	}
		
	//Check for the validity of the dataset
	result = is_valid(head);
	
	if (result == TRUE)
		printf("\nResult = %d\n", result);
	else{
		printf("\nThe dataset is not in proper order.\n");
		return;
	}
		
	display(head);
	
	//printf("%p", head);
	//Displaying the second string values of the list
	disp_second_string_values(head);
	
	//Exchanging information between the first node and last node
	if(head != NULL)
		end_node = exchange_between_first_last(head);
	
	printf("\n\nThe updated list after changing first and last node is \n");
	display(head);
	
	if(strcmp(end_node->c3, head->c1) != 0)
		printf("\nString not matching\n");
	
}
