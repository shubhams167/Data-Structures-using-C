/****************************************************************************************************
*	This program is an implementation of a queue built using array. Operations such 				
*	as insertion, deletion, peek and display are available in this menu-driven program.				
*																										
*	Author: Shubham Singh																			
*	Date: 21 Aug 2018																				
****************************************************************************************************/

#include<stdio.h>

#define MAX 50

/************************************************************************************************************************************
*	FUNCTION:	This function inserts an element at rear of the queue.
*	INPUT:		This function takes four parameters: Array queue, address of front, address of rear and value to be inserted.
*	OUTPUT:		None.
************************************************************************************************************************************/
void insertElement(int *queue, int *front, int *rear, int val)
{
	if(*rear < MAX - 1)
	{	
		*rear = *rear + 1;
		queue[*rear] = val;
		if(*front == -1)
			*front = *front + 1;
	}
	else
		printf("OVERFLOW!\n");
}

/************************************************************************************************************************************
*	FUNCTION:	This function deletes an element from the front of the queue.
*	INPUT:		This function takes three parameters: Array queue, address of front and address of rear.
*	OUTPUT:		Returns value deleted.
************************************************************************************************************************************/
int deleteElement(int *queue, int *front, int *rear)
{
	
	if(*front == -1 || *front > *rear)
		printf("UNDERFLOW!\n");
	else
	{
		int val = queue[*front];
		*front = *front + 1;
		return val;
	}
}

/************************************************************************************************************************************
*	FUNCTION:	This function returns value at front of the queue.
*	INPUT:		This function takes three parameters: Array queue, address of front and address of rear.
*	OUTPUT:		Returns value at front of the queue.
************************************************************************************************************************************/
int peek(int *queue, int *front, int *rear)
{
	if(*front == -1 || *front > *rear)
		printf("UNDERFLOW!\n");
	else
		return queue[*front];
}

/************************************************************************************************************************************
*	FUNCTION:	This function display all elements in the queue.
*	INPUT:		This function takes three parameters: Array queue, address of front and address of rear.
*	OUTPUT:		None.
************************************************************************************************************************************/
void displayQueue(int *queue, int *front, int *rear)
{
	if(*front == -1 || *front > *rear)
		printf("Empty\n");
	else
		for(int i = *front; i <= *rear; i++)
		{
			if(i == *rear)
				printf("%d\n", queue[i]);
			else
				printf("%d <-- ", queue[i]);
		}
}

/*Main function*/
int main()
{
	int queue[MAX], front = -1, rear = -1;
	int option, val;
	do
	{
		printf("********MAIN MENU*********\n");
		printf("1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Peek\n");
		printf("4. Display queue\n");
		printf("Selection(Enter 0 to exit): ");
		scanf("%d", &option);
		switch(option)
		{
			case 0:		break;
			
			case 1:		printf("Enter value to insert: ");
						scanf("%d", &val);
						insertElement(queue, &front, &rear, val);		
						break;
						
			case 2:		val = deleteElement(queue, &front, &rear);								
						printf("Element deleted: %d\n", val);
						break;
						
			case 3:		printf("Value at first: %d\n", peek(queue, &front, &rear));
						break;
						
			case 4:		printf("Queue: ");
						displayQueue(queue, &front, &rear);
						break;
			
			default:	printf("Wrong input\n");
		}
	}while(option != 0);
	return 0;
}
