#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *l_add;
	int data;
	struct node *r_add;
}node;

typedef struct search_loc
{
	struct node *loc;
}search_loc;

node *createnode(int value)
{
	node *n;
	
	n = (node *)malloc(sizeof(node));
	
	n->data = value;
	n->l_add = NULL;
	n->r_add = NULL;
	
	return n;
}

void searchlocation(node *root, int value, search_loc *s_loc)
{
	if (root == NULL)
		return;
		
	searchlocation(root->l_add, value, s_loc);
	searchlocation(root->r_add, value, s_loc);
	
	if (root->data == value)
	{
		//printf("\nEntered\n");
		s_loc->loc = root;
	}
}

void leftentry(node *root)
{
	node *n;
	search_loc *s_loc;
	int search_value, value;
	
	s_loc = (search_loc *)malloc(sizeof(search_loc));
	s_loc->loc = NULL;
	
	printf("\nEnter the value of the parent node \n");
	scanf("%d", &search_value);
	
	searchlocation(root, search_value, s_loc);
	
	if (s_loc->loc == NULL)
	{
		printf("\nThe value entered is not present in the tree\n");
	}
	
	else
	{
		if (s_loc->loc->l_add != NULL)
		{
			printf("\nAlready a value exists on its left\n");
		}
		
		else
		{
			printf("\nEnter the value of the node\n");
			scanf("%d", &value);
			
			n = createnode(value);
			
			s_loc->loc->l_add = n;
		}
	}
}

void rightentry(node *root)
{
	node *n;
	search_loc *s_loc;
	int search_value, value;
	
	s_loc = (search_loc *)malloc(sizeof(search_loc));
	s_loc->loc = NULL;
	
	printf("\nEnter the value of the parent node \n");
	scanf("%d", &search_value);
	
	searchlocation(root, search_value, s_loc);
	
	if (s_loc->loc == NULL)
	{
		printf("\nThe value entered is not present in the tree\n");
	}
	
	else
	{
		if (s_loc->loc->r_add != NULL)
		{
			printf("\nAlready a value exists on its right\n");
		}
		
		else
		{
			printf("\nEnter the value of the node\n");
			scanf("%d", &value);
			
			n = createnode(value);
			
			s_loc->loc->r_add = n;
		}
	}
}

void inorder(node *root)
{
	if (root == NULL)
		return;
		
	inorder(root->l_add);
	printf("%d\t", root->data);
	inorder(root->r_add);
}

void preorder(node *root)
{
	if (root == NULL)
		return;
		
	printf("%d\t", root->data);
	preorder(root->l_add);
	preorder(root->r_add);
}

void postorder(node *root)
{
	if (root == NULL)
		return;
		
	postorder(root->l_add);
	postorder(root->r_add);
	printf("%d\t", root->data);
}

int treeheight(node *root)
{
	if (root == NULL)
		return 0;
		
	int left_height = treeheight(root->l_add);
	int right_height = treeheight(root->r_add);
	
	if (left_height > right_height)
		return (left_height + 1);
		
	else
		return (right_height + 1);
}

void display(node *root, int l, int blank)
{
	int i;
	
	if (root == NULL)
	{
		return;
	}
		
	if (l == 1)
	{
		for (i = 0; i<blank; i++)
		{
			printf(" ");
		}
		
		printf("%d ", root->data);
	}
	
	else if (l >= 1)
	{
		display(root->l_add, l - 1, blank);
		display(root->r_add, l - 1, blank);
	}
}

void printtree(node *root, int blank, int height)
{
	int i = 0;
	
	blank = 10 * height;
	
	for (i = 1; i<=height; i++)
	{
		display(root, i, blank);
		blank -= 10;
		printf("\n\n");
	}
}

int Choice()
{
	int choice;
	printf("\n\n");
	printf("1-> Insert left\n");
	printf("2-> Insert Right\n");
	printf("3-> Height of the tree\n");
	printf("4-> Inorder\n");
	printf("5-> Preorder\n");
	printf("6-> Postorder\n");
	printf("7-> Display\n");
	printf("0-> Exit\n\n");
	printf("Enter your choice\n");
	scanf("%d", &choice);
	
	return choice;
}

void main()
{
	node *root;
	int value, choice = 1, height;
	
	root = NULL;
	
	printf("\nEnter the value of the root\n");
	scanf("%d", &value);
	
	root = createnode(value);
	
	printf("\nThe root data is %d\n", root->data);
	
	while (choice != 0)
	{
		choice = Choice();
		
		if (choice == 1)
		{
			leftentry(root);
		}
		
		else if (choice == 2)
		{
			rightentry(root);
		}
		
		else if (choice == 3)
		{
			height = treeheight(root);
			
			printf("\nThe height of the tree is = %d\n", height);
		}
		
		else if (choice == 4)
		{
			printf("\nThe inorder of the tree is\n");
			inorder(root);
		}
		
		else if (choice == 5)
		{
			printf("\nThe preorder of the tree is\n");
			preorder(root);
		}
		
		else if (choice == 6)
		{
			printf("\nThe postorder of the tree is\n");
			postorder(root);
		}
		
		else if (choice == 7)
		{
			height = treeheight(root);
			
			printf("\nThe tree looks like \n");
			printtree(root, 0, height);
		}
		
		else if (choice == 0)
		{
			printf("\n\nTHANK YOU !!!\n\n");
		}
		
		else
		{
			printf("\nPlease enter the right choice\n");
		}
	}
}
