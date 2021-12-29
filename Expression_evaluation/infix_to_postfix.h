#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining structure
typedef struct stack
{
	int top;
	int *item;
}stack;

void push(stack *s, int c)
{
	s->item[++s->top] = c;
}

int pop(stack *s)
{
	return s->item[s->top--];
}

int precedence(char c)
{
	if(c == '+' || c == '-')
		return 1;
		
	else if (c == '*' || c == '/')
		return 2;
	
	else if (c == '^')
		return 3;
		
	else 
		return -1;
}

int infix_to_postfix(stack *s, char *math_expression)
{
	int i = 0;
	int k = 0;
	char c;
	for(i = 0; i<strlen(math_expression); i++)
	{
		//printf("math = %d\n", math_expression[i]);
		if(math_expression[i] == '(')
		{
			push(s, math_expression[i]);
		}
	
		else if(math_expression[i] == ')')
		{
			while(s->top!=-1 && s->item[s->top] != '(')
			{
				c = pop(s);
				math_expression[k++] = c;
			}
			pop(s);
		}
	
		else if (math_expression[i] == '+' || math_expression[i] == '-' || math_expression[i] == '*' || math_expression[i] == '/' || math_expression[i] == '^')
		{
			//printf("Entered");
			while(s->top != -1 && precedence(math_expression[i]) <= precedence(s->item[s->top]))
			{
				c = pop(s);
				//printf("The pop character is = %c for i = %d top = %d\n", c, i, s->top);
				math_expression[k++] = c;
			}
			push(s, math_expression[i]);
		}
	
		else
		{
			math_expression[k++] = math_expression[i];
		}
	}
	
	while(s->top != -1)
	{
		math_expression[k++] = pop(s);
	}
	
	return k;
}

void math_expression_conversion(char *expression, char *math_expression)
{
	char *a;
	int i = 0;
	int j = 0;
	int n = 0;
	int count = 0;
	int k = 0;
	
	for (i=0; i<strlen(expression); i++)
	{
		a = (char *)malloc(sizeof(char));
		
		if(expression[i] == '(')
		{
			math_expression[k++] = expression[i];
			j = i+1;
			continue;
		}
		
		else if(expression[i] == ')')
		{
			strncpy(a, expression+j, count);
			n = atoi(a);
			math_expression[k++] = n;
			printf("The number is %d \n", n);
			j = i+2;
			count = 0;
			math_expression[k++] = expression[i];
		}
		
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
		{
			if(count > 0)
			{
				strncpy(a, expression+j, count);
				n = atoi(a);
				math_expression[k++] = n;
				printf("The number is %d \n", n);
				j = i+1;
				count = 0;
			}
			math_expression[k++] = expression[i];
		}
		else
		{
			count += 1;
		}
	}
	if (count > 0)
	{
		strncpy(a, expression+j, count);
		n = atoi(a);
		math_expression[k++] = n;
		printf("The number is %d \n", n);
		j = i+1;
		count = 0;
	}
}

char* final_postfix_expression(char *math_expression, int upper_limit)
{
	char *postfix;
	
	postfix = (char *)malloc(sizeof(char));
	
	strncpy(postfix, math_expression, upper_limit);
	
	return postfix;
}

