#include<stdio.h>
#include<stdlib.h>
#define num 5
typedef int datatype;
typedef struct stack
{
	datatype top;
	datatype item[num];
}list;


datatype isempty(datatype p)
{
	//printf("%d\n",l->top);
	if(p==-1)
	{
		return 1;
	}
	else
		return 0;
}

datatype isfull(datatype p)
{
	if(p==(num-1))
	{
		return 1;
	}
	else
		return 0;
}

void push(list *l,datatype p)
{
	//datatype p;
	//printf("%d",l->top);
	if(isfull(l->top)==1)
	{
		printf("\nOverflow\n\n");
		return;
	}
	else
	{
		l->top+=1;
		l->item[l->top]=p;
		return;
	}
}

datatype pop(list *l)
{
	//printf("%d\n",l->top);
	if(isempty(l->top)==1)
	{
		printf("\nUnderflow\n\n");
		return 0;
	}
	else
	{
		return l->item[l->top--];
	}
}

void display(list *l)
{
	int i =0;
	
	if (l->top == -1)
	{
		printf("Stack is empty\n\n");
		return;
	}
	
	for(i = l->top; i>=0; i--)
	{
		printf("%d <-", l->item[i]);
	}
	printf("\n\n");
}

datatype choice1()
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
	list l;datatype p;
	l.top=-1;
	datatype choice,po;
	do
	{
		choice=choice1();
		
		if (1 == choice)
		{
			printf("Enter the value ");
			scanf("%d",&p);
			push(&l,p);
		}
		
		else if(2 == choice)
		{
			po=pop(&l);
			if(po!=0)
			{
				printf("The pop value is= %d\n",po);
			}
		}
		else if(3 == choice)
		{
			display(&l);
		}
		else if (0 == choice)
		{
			return;
		}
		else
			printf("\nWrong input\n\n");
		
	}while (0 != choice);
}
