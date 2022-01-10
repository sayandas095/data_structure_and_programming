#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int *userInputs(int *size)
{
	int *arr, i;
	
	//Asking user for the number of nodes
	printf("\nPlease enter the number of elements you want :- ");
	scanf("%d", size);
	
	//Defining the array
	arr = (int *)malloc(*size * sizeof(int));
	
	printf("\nPlease enter the values :- ");
	for (i = 0; i < *size; i++)
	{
		printf("\nElement %d :- ", i);
		scanf("%d", &arr[i]);
	}
	
	return arr;
}

int findingMaximumDigits(int *arr, int size)
{
	int max = INT_MIN, i = 0, element = 0, digitCount = 0;
	
	//Finding the maximum element from the array
	for (i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	
	//finding the number of digits for that element
	element = max;
	while (element > 0)
	{
		digitCount += 1;
		element = element / 10;
	}
	
	return digitCount;
	
}

void countSort(int *arr, int size, int pass)
{
	int countArray[10], i = 0, index = 0, cumulativeCount[10], newArray[size];
	
	//Initializing the count array
	for (i = 0; i < 10; i++)
	{
		countArray[i] = 0;
	}
	
	//Travelling through the input array and updating the count array
	for (i = 0; i < size; i++)
	{
		index = (arr[i] / (int)pow(10, (pass - 1))) % 10;
		countArray[index] += 1; 
	}
	
	cumulativeCount[0] = countArray[0];
	for (i = 1; i < 10; i++)
	{
		cumulativeCount[i] = cumulativeCount[i - 1] + countArray[i];
	}
	
	//Sorting the array on the basis of the pass
	for (i = size - 1; i >= 0; i--)
	{
		index = (arr[i] / (int)pow(10, (pass - 1))) % 10;
		cumulativeCount[index] -= 1;
		newArray[cumulativeCount[index]] = arr[i];
	}
	
	for (i = 0; i < size; i++)
	{
		arr[i] = newArray[i]; 
	}
	
}

void radixSort(int *arr, int size)
{
	int maxDigits = 0, pass = 0, i;
	
	//Finding the maximum number of digits in the input array
	maxDigits = findingMaximumDigits(arr, size);
	
	for (pass = 1; pass <= maxDigits; pass++)
	{
		countSort(arr, size, pass);
	}
	
	printf("\n\nThe sorted array is :- ");
	for (i = 0; i < size; i++)
	{
		printf("%d\t",arr[i]);
	}
}

void main()
{
	int *arr, size = 0, i;
	
	arr = userInputs(&size);
	
	radixSort(arr, size);
	
}
