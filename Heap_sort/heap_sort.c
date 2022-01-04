#include <stdio.h>
#include <stdlib.h>

int Main_choice()
{
	int choice;
	printf("\n1-> Min-heapify\n");
	printf("2-> Max-heapify\n");
	printf("\nEnter your choice\n");
	scanf("%d", &choice);
	
	return choice;
}

int Choice()
{
	int choice;
	printf("\n1-> Build Heap by inserting some integers\n");
	printf("2-> Insert a key into heap\n");
	printf("3-> Delete function\n");
	printf("4-> Sort function\n");
	printf("5-> To get back to the main menu\n");
	printf("0-> Exit\n");
	printf("\nEnter your choice\n");
	scanf("%d", &choice);
	
	return choice;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void min_heapify(int *array, int pos, int size)
{
	int smallest = pos;
	int left = 2 * pos + 1;
	int right = 2 * pos + 2;
	
	if (left < size && array[left] < array[smallest])
	{
		smallest = left;
	}
	
	if (right < size && array[right] < array[smallest])
	{
		smallest = right;
	}
	
	if (smallest != pos)
	{
		swap(&array[pos], &array[smallest]);
		min_heapify(array, smallest, size);
	}
}

void max_heapify(int *array, int pos, int size)
{
	int largest = pos;
	int left = 2 * pos + 1;
	int right = 2 * pos + 2;
	
	if (left < size && array[left] > array[largest])
	{
		largest = left;
	}
	
	if (right < size && array[right] > array[largest])
	{
		largest = right;
	}
	
	if (largest != pos)
	{
		swap(&array[pos], &array[largest]);
		max_heapify(array, largest, size);
	}
}

int *build_heap(int *array, int main_choice, int *size)
{
	int i = 0;
	int *new_array;
	
	//Defining size and size should be greater than 0
	while (*size < 1)
	{
		printf("\nEnter the number of elements you want to insert\n");
		scanf("%d", size);
	}
	
	//defining the array
	new_array = (int *)malloc((*size) * sizeof(int));
	
	//Inseting elements to the array
	printf("\nEnter the elements to the array\n");
	for (i = 0; i<*size; i++)
	{
		scanf("%d", &new_array[i]);
	}
	
	array = new_array;
	
	//Building the heap
	if (main_choice == 1)
	{
		for (i = (*size / 2) - 1; i>=0; i--)
		{
			min_heapify(array, i, *size);
		}
		
		//Displaying the min heap
		printf("\nAfter the min heap the array look like :-\n");
		for (i = 0; i<*size; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\n");
	}
	
	if (main_choice == 2)
	{
		for (i = (*size / 2) - 1; i>=0; i--)
		{
			max_heapify(array, i, *size);
		}
		
		//Displaying the max heap
		printf("\nAfter the max heap the array look like :-\n");
		for (i = 0; i<*size; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\n");
	}
	
	return array;
}

void insert(int *array, int main_choice, int *size)
{
	int *new_array;
	int i;
	
	new_array = (int *)realloc(array,(*size + 1)*sizeof(int));
	
	/*for (i = 0; i<size; i++)
	{
		new_array[i] = array[i];
	}*/
	
	*size += 1;
	
	printf("\nEnter the key value\n");
	scanf("%d", &new_array[*size - 1]);
	
	/*printf("\nAfter the insertion the array look like :-\n");
	for (i = 0; i<*size; i++)
	{
		printf("%d\t", new_array[i]);
	}
	printf("\n");*/
	
	array = new_array;
	
	//Building the heap
	if (main_choice == 1)
	{
		for (i = (*size / 2) - 1; i>=0; i--)
		{
			min_heapify(array, i, *size);
		}
		
		//Displaying the min heap
		printf("\nAfter the min heap the array look like :-\n");
		for (i = 0; i<*size; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\n");
	}
	
	if (main_choice == 2)
	{
		for (i = (*size / 2) - 1; i>=0; i--)
		{
			max_heapify(array, i, *size);
		}
		
		//Displaying the max heap
		printf("\nAfter the max heap the array look like :-\n");
		for (i = 0; i<*size; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\n");
	}
	
	//return size;
}

void delete(int *array, int main_choice, int *size)
{
	int i;
	
	printf("\nThe deleted value is %d\n", array[0]);
	
	swap(&array[0], &array[*size - 1]);
	
	*size -= 1;
	
	if (main_choice == 1)
	{
		min_heapify(array, 0, *size);
	}
	
	else if (main_choice == 2)
	{
		max_heapify(array, 0, *size);
	}
}

void sort(int *array, int main_choice, int size)
{
	int i;
	
	for (i = (size - 1); i>0; i--)
	{
		swap(&array[0], &array[i]);
		
		if (main_choice == 1)
		{
			min_heapify(array, 0, (i));
		}
		
		if (main_choice == 2)
		{
			max_heapify(array, 0, (i));
		}
	}
	
	//Displaying the sorted array
	printf("\nThe sorted array look like :-\n");
	for (i = 0; i<size; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}

void main()
{
	int choice = 1, main_choice = 1, size = -1;
	int *array;
	
	array = (int *)malloc(sizeof(int));
	
	main_choice = Main_choice();
	
	while (choice != 0)
	{
		choice = Choice();
		
		if (choice == 1)
		{
			size = 0;
			array = build_heap(array, main_choice, &size);
		}
		
		else if (choice == 2)
		{
			if (size == -1)
				size = 0;
			insert(array, main_choice, &size);
		}
		
		else if (choice == 3)
		{
			delete(array, main_choice, &size);
		}
		
		else if (choice == 4)
		{
			sort(array, main_choice, size);
		}
		
		else if (choice == 5)
		{
			main_choice = Main_choice();
		}
		
		else if(choice == 0)
		{
			printf("\n\t\tTHANK YOU!!!\n");
			return;
		}
		
		else
		{
			printf("\nPlease enter a correct input\n");
		}
	}
}
