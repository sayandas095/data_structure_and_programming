#include "infix_to_postfix.h"
#include<math.h>

int postfix_expression_evaluation(stack *s, char *postfix)
{
	int i = 0, total = 0;
	int op1 = 0, op2 = 0;
	
	for (i=0; i<strlen(postfix); i++)
	{
		if (postfix[i] == '+')
		{
			op1 = pop(s);
			op2 = pop(s);
			
			total = (op2 + op1);
			
			push(s, total);
			
			//printf("i = %d, op1 = %d, op2 = %d, (op2 + op1) = %d, total = %d\n\n", i, op1, op2, (op1 + op2), total);
		}
		
		else if (postfix[i] == '-')
		{
			op1 = pop(s);
			op2 = pop(s);
			
			total = (op2 - op1);
			
			push(s, total);
			
			//printf("i = %d, op1 = %d, op2 = %d, (op2 - op1) = %d, total = %d\n\n", i, op1, op2, (op2 - op1), total);
		}
		
		else if (postfix[i] == '*')
		{
			op1 = pop(s);
			op2 = pop(s);
			
			total = (op2 * op1);
			
			push(s, total);
			
			//printf("i = %d, op1 = %d, op2 = %d, (op2 * op1) = %d, total = %d\n\n", i, op1, op2, (op2 * op1), total);
		}
		
		else if (postfix[i] == '/')
		{
			op1 = pop(s);
			op2 = pop(s);
			
			total = (op2 / op1);
			
			push(s, total);
			
			//printf("i = %d, op1 = %d, op2 = %d, (op2 / op1) = %d, total = %d\n\n", i, op1, op2, (op2 / op1), total);
		}
		
		else if (postfix[i] == '^')
		{
			op1 = pop(s);
			op2 = pop(s);
			
			total = ((int)pow(op2, op1));
			
			push(s, total);
			
			//printf("i = %d, op1 = %d, op2 = %d, (op2 ^ op1) = %d, total = %d\n\n", i, op1, op2, ((int)pow(op2, op1)), total);
		}
		else
		{
			push(s, postfix[i]);
			//printf("i = %d, postfix[i] = %d\n\n", i, postfix[i]);
		}
	}
	
	return pop(s);
}

void main()
{
	int i = 0, value = 0;
	int upper_limit = 0;
	stack s;
	char *expression, *math_expression, *postfix;
	
	expression = (char *)malloc(sizeof(char));
	math_expression = (char *)malloc(sizeof(char));
	
	//Taking input from the user
	printf("Enter the expression\n");
	scanf("%s", expression);
	
	//Initializing the stack parameters
	s.top = -1;
	s.item = (int *)malloc(strlen(expression)*sizeof(int));
	
	//Converting the array in desired form
	math_expression_conversion(expression, math_expression);
	
	//Converting infix to postfix
	upper_limit = infix_to_postfix(&s, math_expression);
	
	//Final postfix expression
	postfix = final_postfix_expression(math_expression, upper_limit);
	
	//reinitializing the stack parameters
	s.top = -1;
	
	//Evaluating postfix expression
	value = postfix_expression_evaluation(&s, postfix);
	
	//Priting the expression
	printf("The expression is = ");
	for(i = 0; i<strlen(postfix); i++)
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
			printf("%c", postfix[i]);
		
		else
			printf("%d", postfix[i]);
	}
	printf("\n\n");
	
	//Printing the value of the postfix expression
	printf("The value of the expression is %d\n\n", value);
}
