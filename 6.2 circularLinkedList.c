//	Program to demonstrate circular linked list

#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
}*start = NULL;

//Function to create circular linked list
void createList()
{
	struct	node *newNode = NULL,*ptr = NULL;
	int num;
	if(start != NULL)
	{
		printf("\nList already exists\n");
		return;
	}
	printf("\nEnter -1 to end\nEnter number to add in list: ");
	scanf("%d",&num);
	if(num == -1)
		return;	
	while(num != -1)
	{	
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = num;
		if(start == NULL)
		{
			newNode->next = NULL;
			start = newNode;
			ptr = start;
		}
		else
		{
			newNode->next = NULL;
			ptr->next = newNode;
			ptr = ptr->next;
		}
		printf("\nEnter -1 to end\nEnter number to add in list: ");
		scanf("%d",&num);
	}
	newNode->next = start; 
	printf("\nCircular list created ssuccessfully.\n");
}

//Function to print list
void printList()
{
	struct node *ptr = start;
	printf("\nList: ");
	if(ptr == NULL)
	{
		printf("Empty");
	}
	else
	do
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}while(ptr != start);
	printf("\n\n");
}

//Insert node at beginning
void insertBeg()
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node)),*ptr = start;
	int num;
	printf("\nEnter number to add in list: ");
	scanf("%d",&num);
	while(ptr->next != start)
		ptr = ptr->next;
	newNode->data = num;
	newNode->next = start;
	start = newNode;
	ptr->next = start;
	printf("Node added successfully.\n");
}

//Function to insert node at the end of the list
void insertEnd()
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node)),*ptr = start;
	int num;
	printf("\nEnter number to be added: ");
	scanf("%d",&num);
	newNode->data = num;
	while(ptr->next != start)
		ptr = ptr->next;
	newNode->next = start;
	ptr->next = newNode;
	printf("\nNode added Successfully\n");
}

//Function to delete node at the beginning of the list
void deleteBeg()
{
	struct node *ptr = start;
	while(ptr->next != start)
		ptr = ptr->next;
	ptr->next = start->next;
	free(start);
	start = ptr->next;
	printf("\nDeletion Successful\n");
}

//Function to delete node at the end of the list
void deleteEnd()
{
	struct node *ptr = start;
	while(ptr->next->next != start)
		ptr = ptr->next;
	free(ptr->next);
	ptr->next = start;
	printf("\nDeletion Successful\n");
}

//Function to delete whole list
void deleteList()
{
	//struct node *ptr = start;
	while(start->next != start)
	{
		deleteBeg();
	}
	free(start);
	start = NULL;
}

//Main function
int main()
{
	int option;
	do
	{
		printf("*********MAIN MENU*********");
		printf("\n\n1. Create circular linked list");
		printf("\n2. Display the list");
		printf("\n3. Insert node at the beginning");
		printf("\n4. Insert node at the end");
		printf("\n5. delete node at the beginning");
		printf("\n6. delete node at the end");
		printf("\n7. delete the list");
		printf("\n8. EXIT");
		printf("\n\nEnter option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: createList();break;
			case 2: printList();break;
			case 3: insertBeg();break;
			case 4: insertEnd();break;
			case 5: deleteBeg();break;
			case 6: deleteEnd();break;
			case 7: deleteList();break;
		}
		
	}while(option != 8);
	return 0;
}
