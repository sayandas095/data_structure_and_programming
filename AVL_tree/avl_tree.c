#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	int height;
	struct node *l_add;
	struct node *r_add;
}node;

typedef struct sum
{
	int total;
}sum;

int maximum(int a, int b)
{
	return (a > b)?a:b;
}

int height(node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	return root->height;
}

int height_tree(node *root)
{
	if (root == NULL)
		return 0;
		
	int l_height = height_tree(root->l_add);
	int r_height = height_tree(root->r_add);
	
	if (l_height > r_height)
		return (l_height + 1);
	else
		return (r_height + 1);
}

node *create_node(int value)
{
	node *n;
	
	n = (node *)malloc(sizeof(node));
	
	n->data = value;
	n->height = 1;
	n->l_add = NULL;
	n->r_add = NULL;
	
	return n;
}

int Balance_Factor(node *root)
{
	if (root == NULL)
		return 0;
	
	return (height(root->l_add) - height(root->r_add));
}

node *rotate_right(node *root)
{
	node *n; node *n_1;
	
	n = root->l_add;
	n_1 = n->r_add;
	
	n->r_add = root;
	root->l_add = n_1;
	
	root->height = maximum(height(root->l_add), height(root->r_add)) + 1;
	n->height = maximum(height(n->l_add), height(n->r_add)) + 1;
	
	root = n;
	
	return root;
}

node *rotate_left(node *root)
{
	node *n; node *n_1;
	
	n = root->r_add;
	n_1 = n->l_add;
	
	n->l_add = root;
	root->r_add = n_1;
	
	root->height = maximum(height(root->l_add), height(root->r_add)) + 1;
	n->height = maximum(height(n->l_add), height(n->r_add)) + 1;
	
	root = n;
	
	return root;
}

node *insert_node(node *root, int value)
{
	int balance_factor = 0;
	
	if (root == NULL)
	{
		return create_node(value);
	}
	
	if (value < root->data)
	{
		root->l_add = insert_node(root->l_add, value);
	}
	
	else
	{
		root->r_add = insert_node(root->r_add, value);
	}
	
	//Getting the height of the newly created node
	root->height = 1 + maximum(height(root->l_add), height(root->r_add));
	
	//Finding the balance factor of that node
	balance_factor = Balance_Factor(root);
	
	//printf("\nThe balance factor is = %d\n", balance_factor);
	
	//Trackling the left left problem
	if (balance_factor > 1 && value < root->l_add->data)
	{
		return rotate_right(root);
	}
	
	//Trackling the right right problem
	if (balance_factor < -1 && value > root->r_add->data)
	{
		return rotate_left(root);
	}
	
	//Trackling the left right problem
	if (balance_factor > 1 && value > root->l_add->data)
	{
		root->l_add = rotate_left(root->l_add);
		return rotate_right(root);
	}
	
	//Trackling the right left problem
	if (balance_factor < -1 && value < root->l_add->data)
	{
		root->r_add = rotate_right(root->r_add);
		return rotate_left(root);
	}
	
	return root;
}

node *leftmost(node *root)
{
	node *n, *prev;
	
	n = root;
	prev = root;
	
	while(n != NULL)
	{
		prev = root;
		n = n->l_add;
	}
	
	return prev;
}

node *delete_node(node *root, int value)
{
	int balance_factor = 0;
	node *n;
	
	if (root == NULL)
	{
		return root;
	}
	
	if (value < root->data)
	{
		root->l_add = delete_node(root->l_add, value);
	}
	
	else if (value > root->data)
	{
		root->r_add = delete_node(root->r_add, value);
	}
	
	else
	{
		if (root->l_add == NULL && root->r_add == NULL)
		{
			root = NULL;
		}
		
		else if (root->l_add != NULL && root->r_add == NULL)
		{
			root = root->l_add;
		}
		
		else if (root->l_add == NULL && root->r_add != NULL)
		{
			root = root->r_add;
		}
		
		else
		{
			n = leftmost(root->r_add);
			
			root->data = n->data;
			
			root->r_add = delete_node(root->r_add, n->data);
		}
	}
	
	if (root == NULL)
		return root;
	
	//Getting the height of the newly created node
	root->height = 1 + maximum(height(root->l_add), height(root->r_add));
	
	//Finding the balance factor of that node
	balance_factor = Balance_Factor(root);
	
	//printf("\nThe balance factor is = %d\n", balance_factor);
	
	//Trackling the left left problem
	if (balance_factor > 1 && value < root->l_add->data)
	{
		return rotate_right(root);
	}
	
	//Trackling the right right problem
	if (balance_factor < -1 && value > root->r_add->data)
	{
		return rotate_left(root);
	}
	
	//Trackling the left right problem
	if (balance_factor > 1 && value > root->l_add->data)
	{
		root->l_add = rotate_left(root->l_add);
		return rotate_right(root);
	}
	
	//Trackling the right left problem
	if (balance_factor < -1 && value < root->l_add->data)
	{
		root->r_add = rotate_right(root->r_add);
		return rotate_left(root);
	}
	
	return root;
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

void display(node *root, int l)
{
	if (root == NULL)
		return;
		
	if (l == 1)
	{
		printf("%d\t", root->data);
	}
	
	else
	{
		display(root->l_add, l-1);
		display(root->r_add, l-1);
	}
}

void level_order(node *root)
{
	int h = 0, i = 0;
	
	h = height_tree(root);
	
	for (i = 1; i<=h; i++)
	{
		display(root, i);
	}
}

void sum_of_left_sub_tree(node *root, sum *s)
{
	if (root == NULL)
		return;
		
	sum_of_left_sub_tree(root->l_add, s);
	sum_of_left_sub_tree(root->r_add, s);
	s->total += root->data;
}

int Choice()
{
	int choice;
	
	printf("\n1-> Insert");
	printf("\n2-> Delete");
	printf("\n3-> Inorder");
	printf("\n4-> Pre order");
	printf("\n5-> Post order");
	printf("\n6-> Level order");
	printf("\n7-> Sum of left sub tree of the root");
	printf("\n0-> Exit");
	printf("\nEnter your choice\n");
	scanf("%d", &choice);
	
	return choice;
}

void main()
{
	node *root;
	sum *s;
	int choice = 1, value;
	
	printf("\nEnter the value of the root\n");
	scanf("%d", &value);
	
	root = create_node(value);
	
	//printf("The root data is %d\n", root->data);
	
	while (choice != 0)
	{
		choice = Choice();
		
		if (choice == 1)
		{
			printf("\nEnter the value of the node\n");
			scanf("%d", &value);
			
			root = insert_node(root, value);
			
		}
		
		else if (choice == 2)
		{
			printf("\nEnter the value of the node you want to delete\n");
			scanf("%d", &value);
			
			root = delete_node(root, value);
			
			//printf("\nThe left data = %d the right data = %d\n", root->l_add->data, root->r_add->data);
		}
		
		else if (choice == 3)
		{
			printf("\nThe inorder of the tree is\n");
			inorder(root);
			printf("\n\n");
		}
		
		else if (choice == 4)
		{
			printf("\nThe preorder of the tree is\n");
			preorder(root);
			printf("\n\n");
		}
		
		else if (choice == 5)
		{
			printf("\nThe postorder of the tree is\n");
			postorder(root);
			printf("\n\n");
		}
		
		else if (choice == 6)
		{
			printf("\nThe level order of the tree is\n");
			level_order(root);
			printf("\n\n");
		}
		
		else if (choice == 7)
		{
			s->total = 0;
			sum_of_left_sub_tree(root->l_add, s);
			printf("\nThe sum of the left subtree of the root is %d\n\n", s->total);
		}
		
		else if (choice == 0)
		{
			printf("\n\t\tTHANK YOU !!!\n");
			return;
		}
		
		else
		{
			printf("\nPlease provide a correct choice\n\n");
		}
	}
}
