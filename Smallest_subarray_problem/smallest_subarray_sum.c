#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void smallest_subarray_problem(int *array, int size, int n)
{
	int total = 0, i = 0, j = 0, lb = 0, ub = size, min_total = INT_MIN;
	
	for(i = 0; i<size; i++)
	{
		total = 0;
		
		for(j = i; j<size; j++)
		{
			total = total + array[j];
			
			//printf("\nTotal =  %d, (j - i) = %d, (ub - lb) = %d\n", total, (j - i), (ub - lb));
			
			if(total > n && (j - i) < (ub - lb))
			{
				min_total = total;
				lb = i;
				ub = j;
			}
		}
	}
	
	printf("\n\nThe output of the smallest subarray is \n\n");
	for(i = lb; i<=ub; i++)
		printf("%d\t", (array[i]+ (ub - lb + 1)));

	printf("\n\n");
}

void main()
{
	int *array;
	int size;
	int i = 0, n = 0;
	
	//Taking inputs from user
	printf("Enter the size of the array\n");
	scanf("%d", &size);
	
	//Initializing the array
	array = (int *)malloc(size * sizeof(int));
	
	printf("Enter the elements of the array\n");
	for(i = 0; i<size; i++)
	{
		scanf("%d", &array[i]);
	}
	
	printf("\nEnter a number that will act as a boundary in the selection of subarray\n");
	scanf("%d", &n);
	
	//Calling the smallest subarray problem
	smallest_subarray_problem(array, size, n);
	
}
