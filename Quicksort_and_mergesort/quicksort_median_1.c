#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

long int median(long int a[], long int l, long int u)
{
	long int i, j, temp;
	long int b[3], pos[3];
	b[0] = a[l];
	b[1] = a[(u + l)/2];
	b[2] = a[u];
	
	pos[0] = l;
	pos[1] = (u + l) / 2;
	pos[2] = u;
	
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<2; j++)
		{
			if (b[j] < b[j + 1])
			{
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
				
				temp = pos[j];
				pos[j] = pos[j + 1];
				pos[j + 1] = temp;
			}
		}
	}
	
	return pos[1];
}

void quicksort(long int a[],long int l,long int u)
{
	long int pivot,i,j, pos;
	if(l<u)
	{
		i=l;		//l=lower limit	u=upper limit
		j=u+1;
		
		//Finding the median value position of the first, middle, last element
		pos = median(a, l, u);
		
		swap(&a[pos], &a[l]);
		
		pivot=a[l];
		do
		{
			do
			{
				i++;
			}while(a[i]<pivot);
			do
			{
				j--;
			}while(a[j]>pivot);
			if(i<j)
				swap(&a[i],&a[j]);
		}while(i<j);
		swap(&a[l],&a[j]);
		//printf("\nContinuing\n");
		quicksort(a,l,j-1);
		quicksort(a,j+1,u);
	}
}

void main()
{
	long int *a,i;
	double unsorted_data_time_difference, sorted_data_time_difference, almost_sorted_data_time_difference;
	long int n = 4;
	
	clock_t start_time, end_time;
	
	printf("\nTable for pivot 3 (values given in terms of second) :-\n");
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
		start_time = clock();
	
		quicksort(a,0,n-1);
		
		//Ending time
		end_time = clock();
		
		unsorted_data_time_difference = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		
		//printf("\f");
		//printf("\n \t\t\t\tHII\n");
		//Printing the sorted data
		/*printf("\n\nThe sorted data is  ");
		for(i=0;i<n;i++)
			printf("%ld\t",a[i]);*/
		
		//Now the data is sorted and we are applying the quicksort algorithm on the sorted data
		//Starting time 
		start_time = clock();
	
		quicksort(a,0,n-1);
		
		//Ending time
		end_time = clock();
		
		sorted_data_time_difference = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		
		//In the almost sorted data we are trying to chance 10% data of the sorted array
		Suffel(a, n);
		
		//Starting time 
		start_time = clock();
	
		quicksort(a,0,n-1);
		
		//Ending time
		end_time = clock();
		
		almost_sorted_data_time_difference = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		
		printf("\n");
	
		//Printing the time required
		printf("10^%ld\t%lf\t%lf\t%lf\n", i,unsorted_data_time_difference, sorted_data_time_difference, almost_sorted_data_time_difference);
		
	}
	
	printf("\n\n");
}
