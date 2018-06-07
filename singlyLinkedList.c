//	Program to demonstrate singly linked list

#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start = NULL;

//Function to create linked list
int createList()
{
	struct node *newNode, *ptr;
	int num;
	printf("\n\nEnter -1 to end\nEnter number to add in list: ");
	scanf("%d",&num);
	while(num != -1)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		if(start == NULL)
		{	
			newNode->data = num;
			newNode->next = NULL;
			start = newNode;
		}
		else
		{		
			ptr = start;			
			while(ptr->next != NULL)	
				ptr = ptr->next;
			newNode->data = num;
			newNode->next = NULL;
			ptr->next = newNode;
		}
		printf("Enter number to add in list: ");
		scanf("%d",&num);
	}
	printf("Linked List created!\n\n\n");
}

//Function to print elements of list
void printList()
{
	struct node *ptr = start;
	printf("\n\nList: ")
	while(ptr != NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
}

//Main function
int main()
{
	int option;
	do
	{
		printf("*********MAIN MENU*********\n\n");
		printf("1. Create a List\n");
	 	printf("2. Display the list\n");
		printf("3. EXIT\n");
		printf("\nEnter your option: ");
		scanf("%d",&option);		
		switch(option)
	 	{
			case 1:	createList();break;
			case 2: printList();break;
		}
	}while(option != 3);
	return 0;	
}
