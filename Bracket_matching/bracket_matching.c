#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

//Defining structure
typedef struct stack
{
	int top;
	char *item;
}stack;

void push(stack *s, char c)
{
	s->item[++s->top] = c;
}

char pop(stack *s)
{
	if (s->top == -1)
		return FALSE;
		
	return s->item[s->top--];
}

int bracket_match(stack *s, char *expression)
{
	int len = 0, i = 0;
	char c;
	
	len = strlen(expression);
	
	for(i = 0;i<len;i++)
	{
		if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
		{
			push(s, expression[i]);
		}
		else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
		{
			c = pop(s);
			
			//checking for extra closing brakets
			if (c == FALSE)
				return FALSE;
			
			else if ((c == '(' && expression[i] == ')') || (c == '{' && expression[i] == '}') || (c == '[' && expression[i] == ']'))
			{
				continue;
			}
			
			else
				return FALSE;
				
		}
		
		else
			return FALSE;
	}
	
	//checking for extra opening brakets
	if(s->top == -1)
		return TRUE;
	else
		return FALSE;
}

void main()
{
	stack s;
	char *expression;
	int len = 0, result = 0;
	
	expression = (char *)malloc(sizeof(char));
	
	//Taking the user input as expression
	printf("\n\nEnter an expression of brackets\n");
	scanf("%s", expression);
	
	//Initializing stack
	s.top = -1;
	s.item = (char *)malloc(len * sizeof(char));
	
	//Bracket matching function to check the proper match or not
	result = bracket_match(&s, expression);
	
	if (result == TRUE)
		printf("\n\ntrue\n\n\n");
	
	else
		printf("\n\nfalse\n\n\n");
	
	//len = strlen(expression);
	
	//printf("The expression is %d\n", len);
}
