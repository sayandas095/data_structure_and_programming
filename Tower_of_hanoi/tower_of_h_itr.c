#include<stdio.h>
#include<math.h>

#define NUMBER_OF_DISK 3

//Defining stack
typedef struct stack
{
	int top;
	int item[NUMBER_OF_DISK];
}stack;

void push(stack *s, int i)
{
	s->item[++s->top] = i;
}

int pop(stack *s)
{
	if (s->top == -1)
		return -1;
	return s->item[s->top--];
}

void move_disk(stack *source, stack *destination, char *source_c, char *destination_c)
{
	int source_top = pop(source);
	int destination_top = pop(destination);
	
	//printf("\nSource_top = %d, destination_top = %d\n", source_top, destination_top);
	
	//If no element is there in the destination then simply push the source value to the destination
	if(destination_top == -1)
	{
		push(destination, source_top);
		
		printf("\nMove disk from %s to %s\n\n", source_c, destination_c);
	}
	
	//If no element is there in the source then simply push the destination value to the source
	else if(source_top == -1)
	{
		push(source, destination_top);
		
		printf("\nMove disk from %s to %s\n\n", destination_c, source_c);
	}
	
	//If the source value is less than the destination value then keep the destination value as it is and push the source value to the destination
	else if(source_top < destination_top)
	{
		push(destination, destination_top);
		push(destination, source_top);
		
		printf("\nMove disk from %s to %s\n\n", source_c, destination_c);
	}
	
	//If the source value is greater than the destination value then keep the source value as it is and push the destination value to the source
	else if(source_top > destination_top)
	{
		push(source, source_top);
		push(source, destination_top);
		
		printf("\nMove disk from %s to %s\n\n", destination_c, source_c);
	}
}

void disk_movement(stack *source, stack *middle, stack *destination, char *source_c, char *middle_c, char *destination_c)
{
	int i = 1;
	
	//Total number of possible movements can be 2^n - 1
	for(i = 1; i <= (pow(2, NUMBER_OF_DISK) - 1); i++)
	{
		if(i%3 == 1)
		{
			//printf("i = %d, source = %d, destination =    %d, source_name = %s, destination_name = %s", i, source->item[source->top], source->item[destination->top], source_c, destination_c);
			
			move_disk(source, destination, source_c, destination_c);
			//printf("mode disk from %c to %d", source_c, destination_c);
		}
		
		else if(i%3 == 2)
		{
			//printf("i = %d, source = %d, destination =    %d, source_name = %s, destination_name = %s", i, source->item[source->top], source->item[middle->top], source_c, middle_c);
			
			move_disk(source, middle, source_c, middle_c);
		}
		
		else
		{
			//printf("i = %d, source = %d, destination =    %d, source_name = %s, destination_name = %s", i, source->item[destination->top], source->item[middle->top], destination_c, middle_c);
		
			move_disk(destination, middle, destination_c, middle_c);
		}
	}
}

void main()
{
	stack source, middle, destination;
	int i =0;
	char *source_c = "Source", *middle_c = "Middle", *destination_c = "Destination", *temp;
	
	//Initializing the stack parameters
	source.top = -1;
	middle.top = -1;
	destination.top =-1;
	
	//If the number of disk is even then just swaping the destination with the middle one
	if(NUMBER_OF_DISK % 2 == 0)
	{
		temp = destination_c;
		destination_c = middle_c;
		middle_c = temp;
	}
	
	//Puting the disk in the source
	for (i = NUMBER_OF_DISK; i >= 1; i--)
	{
		push(&source, i);
	}
	
	//performing the disk movement
	disk_movement(&source, &middle, &destination, source_c, middle_c, destination_c);	
	
}
