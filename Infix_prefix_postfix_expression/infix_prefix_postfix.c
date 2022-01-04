#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining structure
typedef struct stack
{
	int top;
	int *item;
}stack;

void push(stack *s, char c)
{
	s->item[++s->top] = c;
}

char pop(stack *s)
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

int infix_to_postfix(stack *s, char *expression)
{
	int i = 0;
	int k = 0;
	char c;
	for(i = 0; i<strlen(expression); i++)
	{
		//printf("math = %d\n", expression[i]);
		if(expression[i] == '(')
		{
			if ((i + 1) == strlen(expression) || expression[i + 1] == '+' || expression[i + 1] == '-' || expression[i + 1] == '*' || expression[i + 1] == '/' || expression[i + 1] == '^' )
			{
				printf("\nInvalid expression\n");
				return -1;
			}
			push(s, expression[i]);
		}
	
		else if(expression[i] == ')')
		{
			while(s->top!=-1 && s->item[s->top] != '(')
			{
				c = pop(s);
				expression[k++] = c;
			}
			
			//if the opening bracket is missing for the closing bracket
			if (s->top == -1)
			{
				printf("\nInvalid expression\n");
				return -1;
			}
			
			else if (((i + 1) != strlen(expression)) && (expression[i + 1] != '+' && expression[i + 1] != '-' && expression[i + 1] != '*' && expression[i + 1] != '/' && expression[i + 1] != '^' && expression[i + 1] != ')'))
			{
				printf("\nInvalid expression\n");
				return -1;
			}
			
			pop(s);
		}
	
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
		{
			//printf("Entered");
			
			if (!((expression[i+1]>='a' && expression[i+1] <= 'z') || (expression[i+1]>='A' && expression[i+1] <= 'Z') || expression[i + 1] == '('))
			{
				printf("\nInvalid expression\n");
				return -1;
			}
			
			while(s->top != -1 && precedence(expression[i]) <= precedence(s->item[s->top]))
			{
				c = pop(s);
				//printf("The pop character is = %c for i = %d top = %d\n", c, i, s->top);
				expression[k++] = c;
			}
			push(s, expression[i]);
		}
	
		else
		{
			if (((i + 1) != strlen(expression)) && (expression[i + 1] != '+' && expression[i + 1] != '-' && expression[i + 1] != '*' && expression[i + 1] != '/' && expression[i + 1] != '^' && expression[i + 1] != ')'))
			{
				printf("\nInvalid expression\n");
				return -1;
			}
			expression[k++] = expression[i];
		}
	}
	
	while(s->top != -1)
	{
		expression[k++] = pop(s);
		
		if (expression[k - 1] == '(')
		{
			printf("\nInvalid expression\n");
			return -1;
		}
	}
	
	return k;
}

char* final_postfix_expression(char *expression, int upper_limit)
{
	char *postfix;
	
	postfix = (char *)malloc(sizeof(char));
	
	strncpy(postfix, expression, upper_limit);
	
	return postfix;
}

void main()
{
	int i = 0;
	int upper_limit = 0;
	stack s;
	char *expression, *expression_1, *postfix, temp;
	
	expression = (char *)malloc(sizeof(char));
	expression_1 = (char *)malloc(sizeof(char));
	
	//Taking input from the user
	printf("Enter the expression\n");
	scanf("%s", expression);
	
	strncpy(expression_1, expression, strlen(expression));
	
	//Initializing the stack parameters
	s.top = -1;
	s.item = (int *)malloc(strlen(expression)*sizeof(int));
	
	//Converting infix to postfix
	upper_limit = infix_to_postfix(&s, expression);
	
	if (upper_limit == -1)
		return;
	
	//Final postfix expression
	postfix = final_postfix_expression(expression, upper_limit);
	
	//Priting the expression
	printf("The postfix expression is = ");
	for(i = 0; i<strlen(postfix); i++)
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
			printf("%c", postfix[i]);
		
		else
			printf("%c", postfix[i]);
	}
	printf("\n\n");	
	
	//Begining of prefix
	//Reversing the entire original expression
	for(i = 0; i<(strlen(expression_1) / 2); i++)
	{
		temp = expression_1[i];
		expression_1[i] = expression_1[strlen(expression_1) - i - 1];
		expression_1[strlen(expression_1) - i - 1] = temp;
	}
	
	//Changing the '(' to ')' and ')' to '('
	for(i = 0; i<(strlen(expression_1)); i++)
	{
		if (expression_1[i] == '(')
			expression_1[i] = ')';
		
		else if (expression_1[i] == ')')
			expression_1[i] = '(';
	}
	
	//Converting to prefix
	upper_limit = infix_to_postfix(&s, expression_1);
	
	//Final prefix expression
	postfix = final_postfix_expression(expression_1, upper_limit);
	
	//Printing the prefix expression
	printf("The prefix expression is = ");
	for(i = (strlen(postfix) - 1); i>=0; i--)
	{
		printf("%c", postfix[i]);
	}
	printf("\n\n");	
}


