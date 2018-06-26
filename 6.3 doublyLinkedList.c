//	Program to demonstrate doubly linked list

#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next,*prev;
}*start = NULL;


//Function to create doubly linked list
void createList()
{
	struct node *newNode = NULL,*ptr = NULL;
	if(start != NULL)
	{
		printf("\nList already exists\n");
		return;
	}
	int num;
	printf("\nEnter -1 to end\nEnter number to be added in list: ");
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
			newNode->prev = NULL;
			start = newNode;
			ptr = start;
		}
		else
		{
			newNode->next = NULL;
			newNode->prev = ptr;
			ptr->next = newNode;
			ptr = ptr->next;
		} 
		printf("\nEnter -1 to end\nEnter number to be added in list: ");
		scanf("%d",&num);
	}
}

//Function to print list
void printList()
{
	struct node *ptr = start;
	printf("\nList: ");
	if(start == NULL)
	{
		printf("Empty\n\n");
		return;
	}
	while(ptr != NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
}

//Insert node at the beginning
void insertBeg()
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	int num;
	printf("\nEnter number to insert: ");
	scanf("%d",&num);
	newNode->data = num;
	newNode->prev = NULL;
	newNode->next = start;
	start = newNode;
	printf("Node inserted successfully\n");
}

//Function to insert node at the end
void insertEnd()
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node)),*ptr = start;
	int num;
	printf("\nEnter number to insert: ");
	scanf("%d",&num);
	newNode->data = num;
	newNode->next = NULL;
	while(ptr->next != NULL)
		ptr = ptr->next;
	newNode->prev = ptr;
	ptr->next = newNode;
	printf("Node inserted successfully\n");
}

//Function to delete node at the beginning
void deleteBeg()
{
	struct node *ptr = start;
	start = start->next;
	start->prev = NULL;
	free(ptr);
	printf("Node deleted successfully\n");
}

//Function to delete node at the end of the list
void deleteEnd()
{
	struct node *ptr = start;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->prev->next = NULL;
	free(ptr);
	printf("Node deleted successfully\n");
}

//Function to delete whole list
void deleteList()
{
	struct node *ptr = start;
	while(ptr->next != NULL)
	{
		deleteBeg();
		ptr = ptr->next;
	}
	free(ptr);
	start = NULL;
	printf("List deleted\n");
}

//Function to delete a node at a position
void deleteNode()
{
	struct node *ptr = start;
	int val;
	printf("\nEnter value to delete from the list: ");
	scanf("%d",&val);
	while(ptr->data != val)
		ptr = ptr->next;
	ptr->prev->next = ptr->next;
	free(ptr);
	printf("Deletion successful\n\n");
}

//Main function
int main()
{
	int option;
	do
	{
		printf("*********MAIN MENU*********");
		printf("\n\n1. Create doubly linked list");
		printf("\n2. Display the list");
		printf("\n3. Insert node at the beginning");
		printf("\n4. Insert node at the end");
		printf("\n5. Delete node at the beginning");
		printf("\n6. Delete node at the end");
		printf("\n7. Delete the list");
		printf("\n8. Delete node at a position");
		printf("\n9. EXIT");
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
			case 8: deleteNode();break;
		}
		
	}while(option != 9);
	return 0;
}
