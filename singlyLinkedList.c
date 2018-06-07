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
void createList()
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
			ptr = start;
		}
		else
		{					
			newNode->data = num;
			newNode->next = NULL;
			ptr->next = newNode; 	
			ptr = ptr->next;
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
	printf("\n\nList: ");
	while(ptr != NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
}

//Insertion at beginning
void insertBeg()
{
	struct node *newNode;
	int n;
	printf("\n\nEnter number to add: ");
	scanf("%d",&n);
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n;
	newNode->next = start;
	start = newNode;
	printf("Succesfully inserted.\n")
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
		printf("3. Insert at beginning\n");
		printf("4. EXIT\n");
		printf("\nEnter your option: ");
		scanf("%d",&option);		
		switch(option)
	 	{
			case 1:	createList();break;
			case 2: printList();break;
			case 3: insertBeg();break;
		}
	}while(option != 4);
	return 0;	
}
