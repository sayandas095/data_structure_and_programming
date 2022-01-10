#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int top;
	int *item;
}stack;

typedef struct queue
{
	int rear;
	int front;
	int *item;
}queue;

//Initializing the stack parameters
void initialStack(stack *s, int size)
{
	s->top = -1;
	s->item = (int *)malloc(size * sizeof(int));
}

//Initializing the queue parameters
void initialQueue(queue *q, int size)
{
	q->front = -1;
	q->rear = -1;
	q->item = (int *)malloc(size * sizeof(int));
}

//Taking user inputs and initiazing the stack and queue parameters
int **userInput(stack *s, queue *q, int **graph, int *size)
{
	int i, j, choice = 1, node;
	//Asking user for the number of nodes
	printf("\nPlease enter the number of nodes graph contains :- ");
	scanf("%d", size);
	
	//Terminating for size less than 1
	if (*size < 1)
	{
		printf("\nWrong size is given as input");
		exit(1);
	}
	
	//Initaializing the graph
	graph = (int **)malloc(*size * sizeof(int *));
	
	for (i = 0; i < *size; i++)
	{
		graph[i] = (int *)malloc(*size * sizeof(int));
		
		for (j = 0; j < *size; j++)
		{
			graph[i][j] = 0;
		}
	}
	
	//Taking user inputs for the connections of the nodes
	printf("\n\nPlease input the connecting nodes for each node (first node is labeled as 0 and the last node as (size - 1))");
	for (i = 0; i<*size; i++)
	{
		choice = 1;
		
		printf("\n\nPlease input the connecting nodes for node %d :- ", i);
		
		while(choice != 0)
		{
			scanf("%d", &node);
			
			//checking if the input node is valid or not
			if (node < 0 || node >= *size)
			{
				printf("\n\nYou are giving wrong input node");
				continue;
			}
			
			graph[i][node] = 1;
			
			printf("\nDo you like to input any other nodes for node %d (if no then please enter 0 or else any other number) :- ", i);
			scanf("%d", &choice);
		}
	}
	
	//Initializing queue
	initialQueue(q, *size);
	
	//Initializing stack
	initialStack(s, *size);
	
	return graph;
}

void enqueue(queue *q, int node)
{
	if (q->rear == -1 && q->front == -1)
	{
		q->front = 0;
	}
	
	//placing the value in the cell
	q->rear += 1;
	q->item[q->rear] = node;
}

int dequeue(queue *q)
{
	int n;
	
	//checking for underflow
	if (q->front == -1 && q->rear == -1)
	{
		return -1;
	}
	
	//geting the value
	n = q->item[q->front];
	q->front += 1;
	
	//Reinitializing
	if (q->front == (q->rear + 1))
	{
		q->front = -1;
		q->rear = -1;
	}
	
	return n;
}

int isVisited(int *visitedNodeList, int endMark, int currentNode)
{
	int i = 0;
	
	for (i = 0; i <= endMark; i++)
	{
		if (visitedNodeList[i] == currentNode)
		{
			return 1;
		}
	}
	
	return 0;
}

void bfs(queue *q, int **graph, int size)
{
	int currentVertex, *visitedNodeList, endMark = -1, i, flag = 0;
	
	//Initializing the visited node list
	visitedNodeList = (int *)malloc(size * sizeof(int));
	
	//Taking the starting veretex as input
	printf("\n\nPlease give the starting vertex for bfs ");
	scanf("%d", &currentVertex);
	
	enqueue(q, currentVertex);
	visitedNodeList[++endMark] = currentVertex;
	//printf("\nq->item = %d\n", q->item[0]);
	
	printf("\n\nThe bfs of the graph is :- \t");
	while ((currentVertex = dequeue(q)) != -1)
	{
		//Exploring the graph for the current vertex
		for (i = 0; i<size; i++)
		{
			if (graph[currentVertex][i] == 0)
			{
				continue;
			}
			
			//checking if the current node is visited or not
			flag = isVisited(visitedNodeList, endMark, i);
			
			//If the current vertex is not visited then enqueue it
			if (flag == 0)
			{
				enqueue(q, i);
				visitedNodeList[++endMark] = i;
			}
		}
		
		printf("%d\t", currentVertex);
	}
	
	printf("\n\n");
}

void push(stack *s, int element)
{
	s->top += 1;
	s->item[s->top] = element;
	
	return;
}

int isempty(int p)
{
	if(p == -1)
	{
		return 1;
	}
	else
		return 0;
}

int pop(stack *s)
{
	//printf("%d\n",l->top);
	if(isempty(s->top)==1)
	{
		return -1;
	}
	else
	{
		return s->item[s->top--];
	}
}

void dfs(stack *s, int **graph, int size)
{
	int currentVertex, *visitedNodeList, endMark = -1, i, flag = 0;
	
	//Initializing the visited node list
	visitedNodeList = (int *)malloc(size * sizeof(int));
	
	//Taking the starting veretex as input
	printf("\n\nPlease give the starting vertex for dfs :- ");
	scanf("%d", &currentVertex);
	
	push(s, currentVertex);
	visitedNodeList[++endMark] = currentVertex;
	//printf("\nq->item = %d\n", q->item[0]);
	
	printf("\n\nThe dfs of the graph is :- \t");
	while ((currentVertex = pop(s)) != -1)
	{
		//Exploring the graph for the current vertex
		for (i = 0; i<size; i++)
		{
			if (graph[currentVertex][i] == 0)
			{
				continue;
			}
			
			//checking if the current node is visited or not
			flag = isVisited(visitedNodeList, endMark, i);
			
			//If the current vertex is not visited then enqueue it
			if (flag == 0)
			{
				push(s, i);
				visitedNodeList[++endMark] = i;
			}
		}
		
		printf("%d\t", currentVertex);
	}
	
	printf("\n\n");
}

void displayGraph(int ** graph, int size)
{
	int i, j;
	
	printf("\nThe graph looks like :-\n");
	
	for (i = 0; i < size; i++)
	{
		printf("\n");
		for (j = 0; j < size; j++)
		{
			printf("%d\t", graph[i][j]);
		}
	}
	
	printf("\n\n");
}

int userChoice()
{
	int choice;
	
	printf("\n\n\n1-> Create a graph and display it in adjacency matrix");
	printf("\n2-> Breadth first search (BFS)");
	printf("\n3-> Depth first search (DFS)");
	printf("\n0-> Exit");
	printf("\n\nEnter your choice :- ");
	scanf("%d", &choice);
	
	return choice;
}

void main()
{
	stack s;
	queue q;
	int size = 0, i, j, **graph, choice = 1;
	
	while (0 != choice)
	{
		choice = userChoice();
		
		if (1 == choice)
		{
			//Taking the user's input for the graph
			graph = userInput(&s, &q, graph, &size);
			
			displayGraph(graph, size);
		}
		
		else if (2 == choice)
		{
			if (0 == size)
			{
				printf("\nSorry, the graph has not yet created");
				continue;
			}
				
			bfs(&q, graph, size);
		}
			
		else if (3 == choice)
		{
			if (0 == size)
			{
				printf("\nSorry, the graph has not yet created");
				continue;
			}
				
			dfs(&s, graph, size);
		}
			
		else if (0 == choice)
		{
			printf("\n\t\t\tTHANK YOU !!!\n\n");
			return;
		}
		
		else
			printf("\nPlease give the right choice");
	}
	
}
