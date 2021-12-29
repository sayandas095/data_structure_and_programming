#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int datatype;

typedef struct stack
{
	struct node
	{
		datatype data;
		struct node *next;
	}*top;
}stack;

typedef struct node node;

int isempty(stack st)
{
	if(st.top==NULL)
		return TRUE;
	return FALSE;
}

void push(stack *st,datatype n)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	if(p==NULL)
	{
		printf("\nOverflow\n\n");
		return;
	}
	else
	{
		p->data=n;
		p->next=st->top;
		st->top=p;
	}
	return;
}

datatype pop(stack *st)
{
	node *p;
	datatype n;
	if(isempty(*st)==1)
	{
		printf("\nUnderflow\n\n");
		return 0;
	}
	p=st->top;
	n=p->data;
	st->top=p->next;
	return n;
}

void display(stack *st)
{
	//int i = 0;
	node *p;
	p = st->top;
	
	if(p == NULL)
	{
		printf("Stack is empty\n\n");
		return;
	}
	
	while(p != NULL)
	{
		printf("%d <- ", p->data);
		p = p->next;
	}
	printf("\n\n");
}

int choice1()
{
	datatype choice;
	printf("1-> Push\n");
	printf("2-> Pop\n");
	printf("3-> Display\n");
	printf("0-> Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	return choice;
}

void main()
{
	stack *st;datatype n;
	st=(stack *)malloc(sizeof(stack));
	datatype po;int choice = 1;
	st->top=NULL;
	while (0 != choice)
	{
		choice=choice1();
		if(1 == choice)
		{
			printf("Enter the value ");
			scanf("%d",&n);
			//for(;;)
			push(st,n);
			//printf("pushed");
			
		}
		else if(2 == choice)
		{
			po=pop(st);
			if(po!=0)
			{
				//printf("Address is %d\n",st->top);
				printf("The pop value is= %d\n",po);
			}
			
		}
		else if(3 == choice)
		{
			display(st);
			
		}
		else if(0 == choice)
		{
			return;
			
		}
		else
			printf("\nWrong input\n\n");
			
	}
}
