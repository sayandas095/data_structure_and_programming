//mergesort
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
		a[i] = rand() % n;
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

void merge(long int a[],long int l,long int u,long int size)
{
	long int l1,l2,i,med=(l+u)/2,*b;
	
	b = (long int *)malloc(size * sizeof(long int));
	//printf("l=%d\tu=%dsize=%d\n",l,u,size);
	for(l1=l,l2=med+1,i=l;l1<=med&&l2<=u;i++)
	{
		if(a[l1]>=a[l2])
		{
			b[i]=a[l1++];
		}
		else
		{
			b[i]=a[l2++];
		}
			//printf("%d\n",b[i]);
	}
	while(l1<=med)
	{
		b[i++]=a[l1++];
	}
	while(l2<=u)
	{
		b[i++]=a[l2++];
	}
	//copying the entire values to a from b
	for(i=l;i<=u;i++)
	{
		a[i]=b[i];
	}
	
	free(b);
}

void mergesort(long int a[],long int l,long int u,long int size)
{
	long int med;
	if(l>=u)
		return;
	else
	{
		med=(l+u)/2;
		mergesort(a,l,med,size);
		mergesort(a,med+1,u,size);
		merge(a,l,u,size);
	}
}

void main()
{
	long int *a,i;
	double unsorted_data_time_difference, sorted_data_time_difference, almost_sorted_data_time_difference;
	long int n = 4;
	
	clock_t start_time, end_time;
	
	printf("\nTable for merge sort (values given in terms of second) :-\n");
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
	
		mergesort(a,0,n-1, n);
		
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
	
		mergesort(a,0,n-1, n);
		
		//Ending time
		end_time = clock();
		
		sorted_data_time_difference = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		
		//In the almost sorted data we are trying to chance 1% data of the sorted array
		Suffel(a, n);
		
		//Starting time 
		start_time = clock();
	
		mergesort(a,0,n-1, n);
		
		//Ending time
		end_time = clock();
		
		almost_sorted_data_time_difference = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		
		printf("\n");
	
		//Printing the time required
		printf("10^%ld\t%lf\t%lf\t%lf\n", i,unsorted_data_time_difference, sorted_data_time_difference, almost_sorted_data_time_difference);
		
	}
	
	printf("\n\n");
}
