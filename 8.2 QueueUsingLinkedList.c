/****************************************************************************************************
*	This program is an implementation of a queue built using linked list. Operations such 				
*	as insertion, deletion, peek and display are available in this menu-driven program.				
*																										
*	Author: Shubham Singh																			
*	Date: 30 Aug 2018																				
****************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}NODE; 

typedef struct queue
{
	NODE *front, *rear;
}QUEUE;

/************************************************************************************************************************************
*	FUNCTION:	This function inserts an element at rear of the queue.
*	INPUT:		This function takes two parameters: q of type QUEUE and value to be inserted.
*	OUTPUT:		None.
************************************************************************************************************************************/
void insertElement(QUEUE *q, int val)
{
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = val;
	newNode->next = NULL;
	if(q->front == NULL)
		q->front = q->rear = newNode;
	else
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

/************************************************************************************************************************************
*	FUNCTION:	This function deletes an element from the front of the queue.
*	INPUT:		This function takes one parameter: q of type QUEUE.
*	OUTPUT:		Returns value deleted or -1 if queue is empty.
************************************************************************************************************************************/
int deleteElement(QUEUE *q)
{
	if(q->front == NULL || q->rear == NULL)
		printf("Queue empty!\n");	
	else
	{
		int val = q->front->data;
		NODE *temp = q->front;
		q->front = q->front->next;
		free(temp);
		return val;
	}
	return -1;
}

/************************************************************************************************************************************
*	FUNCTION:	This function returns value at front of the queue.
*	INPUT:		This function takes one parameter: q of type QUEUE.
*	OUTPUT:		Returns value at front of the queue and -1 if queue is empty.
************************************************************************************************************************************/
int peek(QUEUE *q)
{
	if(q->front == NULL || q->rear == NULL)
		printf("Queue empty!\n");
	else
		return q->front->data;
	return -1;
}

/************************************************************************************************************************************
*	FUNCTION:	This function display all elements in the queue.
*	INPUT:		This function takes one parameter: q of type QUEUE.
*	OUTPUT:		None.
************************************************************************************************************************************/
void displayQueue(QUEUE *q)
{
	if(q->front == NULL || q->rear == NULL)
		printf("Empty\n");
	else
	{
		NODE *ptr = q->front;
		while(ptr != NULL)
		{
			if(ptr == q->rear)
				printf("%d\n", ptr->data);
			else
				printf("%d <-- ", ptr->data);
			ptr = ptr->next;
		}
	}
}

/*Driver function*/
int main()
{
	QUEUE q = {NULL, NULL};	//Create an empty queue
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
						insertElement(&q, val);		
						break;
						
			case 2:		val = deleteElement(&q);								
						printf("Element deleted: %d\n", val);
						break;
						
			case 3:		printf("Value at first: %d\n", peek(&q));
						break;
						
			case 4:		printf("Queue: ");
						displayQueue(&q);
						break;
			
			default:	printf("Wrong input\n");
		}
	}while(option != 0);
	return 0;
}
