#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILD 20

typedef struct node
{
	char *data;
	struct node *child[MAX_CHILD];
}node;

typedef struct word
{
	char *name;
	int freq;
	struct word *next;
}word;

typedef struct word_array
{
	char *name;
	int freq;
}word_array;

void insert_word(node *root)
{
	node *n, *n_freq;
	char *value, *cata;
	int freq, i = 0, flag = 0, index, node_freq;
	
	cata = (char *)malloc(sizeof(char));
	value = (char *)malloc(sizeof(char));
	
	printf("Enter the name of the catarogy you want to enter\n");
	scanf("%s", cata);
	printf("Enter the word\n");
	scanf("%s", value);
	printf("Enter the frequency\n");
	scanf("%d", &freq);
	
	n = (node *)malloc(sizeof(node));
	n_freq = (node *)malloc(sizeof(node));
	
	n_freq->data = (char *)malloc(sizeof(char));
	sprintf(n_freq->data, "%d", freq);
	//n_freq->data = (char)freq;
	n_freq->child[0] = NULL;
	
	n->data = value;
	n->child[0] = n_freq;
	n->child[1] = NULL;
	
	//Finding the inputed catagory
	while (i < MAX_CHILD && root->child[i] != NULL)
	{
		if (strcmp(root->child[i]->data, cata) == 0)
		{
			flag = 1;
			index = i;
			break;
		}
		//printf("Ok done");
		i++;
		//n_p = n_p->child[index++];
	}
	
	//printf("Flag = %d, index = %d\n", flag, index);
	
	if (flag == 0)
	{
		printf("\nSorry the catagory you entered is not present\n");
		return;
	}
	
	i = 0;
	flag = 0;
	
	//Finding if the word already present or not
	while (i < MAX_CHILD && root->child[index]->child[i] != NULL)
	{
		//printf("Ok done");
		
		if (strcmp(root->child[index]->child[i]->data, value) == 0)
		{
			flag = 1;
			break;
		}
		i++;
		//n_p = n_p->child[index++];
	}
	
	//flag = 1 determines that the word is present we are just increasing the frequency of that word by 1
	if (flag == 1)
	{
		node_freq = atoi(root->child[index]->child[i]->child[0]->data);
		//printf("\nWord match = %d", node_freq);
		node_freq = node_freq + freq;
		
		sprintf(root->child[index]->child[i]->child[0]->data, "%d", node_freq);
		
		printf("\nThe word is already present and the frequency is updated\n");
		
		return;
	}
	
	root->child[index]->child[i] = n;
	root->child[index]->child[i + 1] = NULL;
}

void insert_catagory(node *root)
{
	node *n, *n_p;
	char *value;
	int index = 0, i = 0, flag = 0;
	
	value = (char *)malloc(sizeof(char));
	
	printf("Give the name of the catagory\n");
	scanf("%s", value);
	
	n = (node *)malloc(sizeof(node));
	
	n->data = value;
	n->child[0] = NULL;
	
	//n_p = root;
	
	while (i < MAX_CHILD && root->child[i] != NULL)
	{
		if (strcmp(root->child[i]->data, value) == 0)
		{
			flag = 1;
			break;
		}
		//printf("Ok done");
		i++;
		//n_p = n_p->child[index++];
	}
	
	if (flag == 1)
	{
		printf("\nThe catagory you entered is already present\n");
		return;
	}
	
	root->child[i] = n;
	root->child[i + 1] = NULL;
	
	//printf("word_1 = %s\n", value);
	
	//return root;
}

void display_catagory(node *root)
{
	int i = 0;
	
	printf("\nThe catagories are :- \n");
	while (root->child[i] != NULL)
	{
		printf("%s\t", root->child[i]->data);
		i++;
	}
	
	printf("\n\n");
}

void display_word(node *root)
{
	int i = 0, j = 0;
	
	while (root->child[i] != NULL)
	{
		printf("\nWords under the catagory %s are :-\n", root->child[i]->data);
		j = 0;
		
		while (root->child[i]->child[j] != NULL)
		{
			printf("%s\t", root->child[i]->child[j]->data);
			j++;
		}
		
		printf("\n\n");
		i++;
	}
}

void degree_of_node(node *root)
{
	int count = 0, i = 0, j = 0;
	char *value;
	
	value = (char *)malloc(sizeof(char));
	
	printf("\nEnter the name of the node\n");
	scanf("%s", value);
	
	//checking the root
	if (strcmp(root->data, value) == 0)
	{
		while (root->child[i] != NULL)
		{
			count += 1;
			i++;
		}
		
		printf("\nThe degree of node %s is %d\n", value, count);
		return;
	}
	
	//Checking for level 1
	i = 0;
	j = 0;
	
	while (root->child[i] != NULL)
	{
		if (strcmp(root->child[i]->data, value) == 0)
		{
			while (root->child[i]->child[j] != NULL)
			{
				count += 1;
				j++;
			}
		
			printf("\nThe degree of node %s is %d\n", value, count);
			return;
		}
		
		i++;
	}
	
	printf("\nThe data you have entered is eighter not present or at the leaf level whose degree will always be 1\n");
}

void depth_of_node(node *root)
{
	int i = 0, j =0, k = 0, count = 0;
	char *value;
	
	value = (char *)malloc(sizeof(char));
	
	printf("\nEnter the name of the node\n");
	scanf("%s", value);
	
	//checking the root
	if (strcmp(root->data, value) == 0)
	{
		printf("\nThe depth of node %s is %d\n", value, count);
		return;
	}
	
	count += 1;
	
	//Checking for level 1
	i = 0;
	j = 0;
	
	while (root->child[i] != NULL)
	{
		if (strcmp(root->child[i]->data, value) == 0)
		{
			printf("\nThe depth of node %s is %d\n", value, count);
			return;
		}
		
		i++;
	}
	
	count += 1;
	
	//Checking for level 2
	i = 0;
	j = 0;
	
	while (root->child[i] != NULL)
	{
		j = 0;
		while (root->child[i]->child[j] != NULL)
		{
			if (strcmp(root->child[i]->child[j]->data, value) == 0)
			{
				printf("\nThe depth of node %s is %d\n", value, count);
				return;
			}
		
			j++;
		}
		i++;
	}
	
	printf("\nThe data you have entered is not present\n");
	
}

void sorting(node *root)
{
	int count = 0, i = 0, j = 0, k = 0;
	word *w, *front, *rear;
	word_array *w_array, temp;
	
	//capturing the words and freq
	while (root->child[i] != NULL)
	{
		j = 0;
		while (root->child[i]->child[j] != NULL)
		{
			count += 1;
			w = (word *)malloc(sizeof(word));
			w->name = root->child[i]->child[j]->data;
			w->freq = atoi(root->child[i]->child[j]->child[0]->data);
			w->next = NULL;
			
			if (count == 1)
			{
				front = w;
				rear = w;
			} 
			
			else
			{
				rear->next = w;
				rear = w;
			}
			
			j++;
		}
		
		i++;
	}
	
	//Now storing those into array
	w_array = (word_array *)malloc(sizeof(word_array)*count);
	w = front;
	
	for (i = 0; i<count; i++)
	{
		w_array[i].name = w->name;
		w_array[i].freq = w->freq;
		
		w = w->next;
	}
	
	//sorting the words in terms of frequency
	for (i = 0; i<count; i++)
	{
		for (j = 0; j < count - 1; j++)
		{
			if (w_array[j].freq < w_array[j + 1].freq)
			{
				temp = w_array[j];
				w_array[j] = w_array[j + 1];
				w_array[j + 1] = temp;
			}
		}
	}
	
	for (i = 0; i<count; i++)
		printf("\n%s\t%d\n", w_array[i].name, w_array[i].freq);
}

int Choice()
{
	int choice;
	printf("\n1-> Insert catagory");
	printf("\n2-> Insert word");
	printf("\n3-> Display catagory");
	printf("\n4-> Display words");
	printf("\n5-> Display degree of a node");
	printf("\n6-> Display depth of a node");
	printf("\n7-> Display words in descending order based on frequency");
	printf("\n0-> Exit");
	printf("\nEnter your choice\n");
	scanf("%d", &choice);
	
	return choice;
}

void main()
{
	node *root;
	node *n;
	
	int choice = 1;
	//Creating a root node
	n->data = "word";
	n->child[0] = NULL;
	
	root = n;
	
	while(choice != 0)
	{
		choice = Choice();
		
		if (choice == 1)
		{
			insert_catagory(root);
		}
		
		else if (choice == 2)
		{
			insert_word(root);
		}
		
		else if (choice == 3)
		{
			display_catagory(root);
		}
		
		else if (choice == 4)
		{
			display_word(root);
		}
		
		else if (choice == 5)
		{
			degree_of_node(root);
		}
		
		else if (choice == 6)
		{
			depth_of_node(root);
		}
		
		else if (choice == 7)
		{
			sorting(root);
		}
		
		else if (choice == 0)
		{
			printf("\n\t\tTHANK YOU !!!\n");
			return;
		}
		
		else
		{
			printf("\nPlease provide a valid input\n");
		}
	}
	
	//printf("word = %s\n", root->child[1]->child[1]->child[0]->data);
}
