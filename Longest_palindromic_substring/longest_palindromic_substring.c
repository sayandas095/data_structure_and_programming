#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *generateSubstring(char *str, int startPoint, int endPoint)
{
	char *subString;
	int i, index = 0;
	
	subString = (char *)malloc(sizeof(char));
	
	for (i = startPoint; i <= endPoint; i++)
	{
		subString[index++] = str[i];
	}
	
	subString[index++] = '\0';
	
	return subString;
}

int isPalindromic(char *subString, int len)
{
	int i;
	
	for (i = 0; i < (len / 2); i++)
	{
		if (subString[i] >= 65 && subString[i] <= 90)
			subString[i] += 32;
			
		if (subString[len - i - 1] >= 65 && subString[len - i - 1] <= 90)
			subString[i] += 32;
		
		if (subString[i] != subString[len - i - 1])
			return 0;
	}
	
	return 1;
}

void longestPalindromicString(char *str)
{
	int len, i, endMark, flag, maxLength = 1, startPoint = 0, endPoint = 0;
	char *subString;
	
	len = strlen(str);
	
	for (i = 0; i < len; i++)
	{
		endMark = len - 1;
		
		while ((endMark - i) >= 1)
		{
			//Generating the sub string
			subString = (char *)malloc(sizeof(char));
			subString = generateSubstring(str, i, endMark);
			
			//Checking if the string is palindromic or not
			flag = isPalindromic(subString, (endMark - i) + 1);
			
			if (flag == 1 && (endMark - i + 1) > maxLength)
			{
				startPoint = i;
				endPoint = endMark;
				maxLength = (endMark - i + 1);
			}
			
			endMark--;
		}
	}
	
	if (maxLength == 1)
		printf("\n\nEach and every individual character in the string is considered as a longest sub string");
	
	else
	{
		printf("\n\nThe maximum substring is :- ");
		for (i = startPoint; i <= endPoint; i++)
			printf("%c", str[i]);
	}
}

void main()
{
	char *str;
	
	str = (char *)malloc(sizeof(char));
	
	//taking the input from the user
	printf("\nPlease enter the string here :- ");
	scanf("%[^\n]s", str);
	
	printf("\nThe input string is :- %s", str);
	
	longestPalindromicString(str);
	
	printf("\n\n\t\t\tTHANK YOU !!!\n\n");
}
