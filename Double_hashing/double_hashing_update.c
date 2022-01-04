#include <stdio.h>
#include <stdlib.h>

int menu()
{
	int ch=0;
	printf("\n1->Insert\n");
	printf("2->Delete\n");
	printf("3->Search\n");
	printf("4->Load Factor\n");
	printf("5->View\n");
	printf("0->Exit\n");
	printf("Enter your choice (0/1/2/3/4/5)\n");
	scanf("%d",&ch);
	return ch;
}

void insert(int *a,int key,int size,int m, int *entries)
{
	int i=0,pos,count=0,secondHashValue=0,value=0;
	pos=key % size;
	value=pos;
	secondHashValue=key % m;
	//printf("%d",pos);
	while(1)
	{	
		if(a[pos]==-1)
		{
			a[pos]=key;
			*entries += 1;
			return;
		}
		else if(++count < size)
		{
			pos=(value+((++i)*secondHashValue))%size;
			printf("The value of the pos=%d\n",pos);
		}
		else
		{
			printf("\nSorry the value cannot be inserted\n");
			return;
		}
	}
}

void display(int *a,int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		if(a[i]==-1)
			printf(" _ ");
		else
			printf(" %d ",a[i]);
	}
}

int search(int *a,int key,int size,int m)
{
	int i=0,count =0,pos,secondHashValue,value=0;
	secondHashValue=key % m;
	pos=key % size;
	value=pos;
	while(count++ <= size)
	{
		if(a[pos] == key)
			return pos;
		else
		{
			pos=(value+((++i)*secondHashValue))%size;
		}
	}
	return -1;
}

int search_for_deletion(int *a,int key,int size,int m, int *i, int *index_mapping)
{
	int count =0,pos, pos1;
	int secondHashValue=key % m;
	pos=key % size;
	int value = pos;
	pos1 = pos;
	index_mapping[pos] = 1;
	
	while(count++ <= size)
	{
		if(a[pos] == key)
			return pos;
		else
		{
			*i = *i + 1;
			pos=(value+((*i)*secondHashValue))%size;
			index_mapping[pos] = 1;
		}
	}
	return -1;
}

void delete(int *a,int key,int size,int m, int *entries)
{
	//printf("Entered\n");
	int *index_mapping;
	int i=0, j = 0;
	int pos, prev_pos;
	int expected_pos = key % size;
	int value = expected_pos;
	int secondHashValue=key % m;
	
	index_mapping = (int *)malloc(size * sizeof(int));
	
	// Initializing the index mapping
	for (j = 0; j < size; j++)
		index_mapping[j] = 0;
		
	pos=search_for_deletion(a,key,size, m, &i, index_mapping);
	//printf("%d",pos);
	if(pos==-1)
		printf("\n Value is not found so not deleted\n");
	else
	{
		// Deleting the value and assigning the position value -1
		printf("\nThe value is deleted\n");
		a[pos]=-1;
		*entries -= 1;
		index_mapping[pos] = 1;
		prev_pos = pos;
		
		// Now updating the deleted position
		while (i < size)
		{
			i = i + 1;
			pos=(value+((i)*secondHashValue))%size;			
			
			// We will be checking if the newly generated positional value suppose to be in the previous position or not
			if ((a[pos] % size) == expected_pos && index_mapping[pos] == 0)
			{
				a[prev_pos] = a[pos];
				a[pos] = -1;
				prev_pos = pos;
				index_mapping[pos] = 1;
			}
			
		} 
	}
}

void load_factor(int size, int *entries)
{
	printf("\nThe load factor is %lf\n", ((double)(*entries) / (double)size));
}

void main()
{
	int size = 0,*a;
	int ch=1,key,i,n,m = 0, entries = 0;
	
	while (size < 10)
	{
		printf("Enter the size of the list (>= 10)\n");
		scanf("%d",&size);
	}
	
	do
	{
		printf("Enter the value of \"m\"for the second hash function (\"m\" should be less than the size of the array)\n");
		scanf("%d",&m);
	}while (m >= size || m == 0);
	
	a=(int *)malloc(size*sizeof(int));
	
	for(i=0;i<size;i++)
	{
		a[i]=-1;
	}
	
	while(ch!=0)
	{
		ch=menu();
		if(ch==1)
		{
			printf("Enter the key");
			scanf("%d",&key);
			insert(a,key,size,m, &entries);
		}
		
		else if(ch==2)
		{
			printf ("Enter the key you want to delete \n");
			scanf("%d",&key);
			delete(a,key,size,m, &entries);
		}
		
		else if(ch==3)
		{
			printf("Enter the key you want to search\n");
			scanf("%d",&key);
			n=search(a,key,size,m);
			if (n==-1)
				printf("\n Key not found\n");
			else
				printf("\n Key is found at position %d\n",n);
		}
		
		else if(ch==4)
		{
			load_factor(size, &entries);
		}
		
		else if (ch == 5)
		{
			display(a,size);
		}
		
		else if(ch==0)
			printf("\n\t\tThank you!!!\n");
		
		else
			printf("\n Please select any option between (0/1/2/3/4/5)");
	}
}
