#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct total_comparision
{
	long int count;
}total_comparision;

void input(long int a[],long int n)
{
	int i;
	srand(time(0));
	//printf("Entered input");
	for(i=0;i<n;i++)
		a[i] = rand() % 100;
	//printf("Completed Entered input");
}

void swap(long int *a,long int *b)
{
	long int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Suffel(long int a[], long int n)
{
	long int i = 0, pos1, pos2, flag = 0;
	
	srand(time(0));
	
	while(i < (int)(0.01 * n))
	{
		//printf("\nEntered for i = %ld\n", i);
		
		pos1 = rand() % (n + 1);
		pos2 = rand() % (n + 1);
		
		if (flag < 10)
		{
			if (a[pos1] != a[pos2])
			{
				swap(&a[pos1], &a[pos2]);
				flag += 1;
				i += 1;
				//printf("\nThe two values are different and the flag = %ld and i = %ld and a[pos1] = %ld and a[pos2] = %ld and positions are %ld and %ld\n", flag, i, a[pos1], a[pos2], pos1, pos2);
			}
			
			continue;
		}
		
		swap(&a[pos1], &a[pos2]);
		i++;
	}
}

void quicksort(long int a[],long int l,long int u, total_comparision *tc)
{
	long int pivot,i,j, pos;
	if(l<u)
	{
		i=l;		//l=lower limit	u=upper limit
		j=u+1;
		
		//Finding the random position
		srand(time(0));
		pos = l + (rand() % (u - l));
		
		//Swaping it with the first position
		swap(&a[pos], &a[l]);
		
		pivot=a[l];
		do
		{
			do
			{
				i++;
				tc->count += 1;
			}while(a[i]<pivot);
			do
			{
				j--;
				tc->count += 1;
			}while(a[j]>pivot);
			if(i<j)
				swap(&a[i],&a[j]);
		}while(i<j);
		swap(&a[l],&a[j]);
		//printf("\nContinuing\n");
		quicksort(a,l,j-1, tc);
		quicksort(a,j+1,u, tc);
	}
}

void main()
{
	total_comparision *tc;	
	
	long int *a,i;
	double unsorted_data_comparision, sorted_data_comparision, almost_sorted_data_comparision;
	long int n = 4;
	
	tc = (total_comparision *)malloc(sizeof(total_comparision));
	
	clock_t start_time, end_time;
	
	printf("\nTable for pivot 2 (values given in terms of comparision) :-\n");
	printf("---------------------------------------------------------\n");
	printf("\nSIZE\tRANDOM\t\tSORTED\t\tALMOST_SORTED\n");
	printf("---------------------------------------------------------\n");
	
	for (i = 4; i < 8; i++)
	{
		n = (long int)pow(10, i);
		//printf("\n clock per sec = %ld\n", CLOCKS_PER_SEC);
		a=(long int *)malloc(n*sizeof(long int));
		//for(i=0;i<n;i++)
		//{	scanf("%d",&a[i]);printf("i=%d,a[i]=%d\t",i,a[i]);}
		input(a, n);
	
		//Starting time 
		//start_time = clock();
		
		tc->count = 0;
		
		quicksort(a,0,n-1, tc);
		
		unsorted_data_comparision = tc->count;
		//Ending time
		//end_time = clock();
		
		//printf("\f");
		//printf("\n \t\t\t\tHII\n");
		//Printing the sorted data
		/*printf("\n\nThe sorted data is  ");
		for(i=0;i<n;i++)
			printf("%ld\t",a[i]);*/
		
		//Now the data is sorted and we are applying the quicksort algorithm on the sorted data
		//Starting time 
		//start_time = clock();
		
		tc->count = 0;
		
		quicksort(a,0,n-1, tc);
		
		sorted_data_comparision = tc->count;
		//Ending time
		//end_time = clock();
		
		//sorted_data_time_difference = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		
		//In the almost sorted data we are trying to chance 1% data of the sorted array
		Suffel(a, n);
		
		//Starting time 
		//start_time = clock();
		
		tc->count = 0;
	
		quicksort(a,0,n-1, tc);
		
		almost_sorted_data_comparision = tc->count;
		
		//Ending time
		//end_time = clock();
		
		//almost_sorted_data_time_difference = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		
		printf("\n");
	
		//Printing the time required
		printf("10^%ld\t%.1lf\t%.1lf\t%.1lf\n", i,unsorted_data_comparision, sorted_data_comparision, almost_sorted_data_comparision);
		
	}
	
	printf("\n\n");
}
