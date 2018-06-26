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
	printf("\n\nEnter -1 to end\nEnter number to be added in list: ");
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
		printf("Enter number to be added in list: ");
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

//Insertion at the beginning
void insertBeg()
{
	struct node *newNode;
	int n;
	printf("\n\nEnter number to be added in list: ");
	scanf("%d",&n);
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n;
	newNode->next = start;
	start = newNode;
	printf("Insertion Success.\n\n");
}

//Insertion at the end
void insertEnd()
{
	struct node *newNode,*ptr = start;
	int n;
	printf("\n\nEnter number to be added in list: ");
	scanf("%d",&n);
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n;
	newNode->next = NULL;
	while(ptr->next !=NULL)
		ptr = ptr->next;
	ptr->next = newNode;
	printf("Insertion Success.\n\n");
}

//Insertion before a value
void insertBefore()
{
	struct node *newNode,*ptr = start,*temp_ptr;
	int n,val;
	printf("\nEnter number to be added in list: ");
	scanf("%d",&n);
	printf("Enter value before which number has to be added in list: ");
	scanf("%d",&val);
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n;
	while(ptr->data != val)
	{
		temp_ptr = ptr;
		ptr = ptr->next;
	}
	if(ptr == start)
	{
		printf("Insertion failed.\n\n");
		return;
	}
	temp_ptr->next = newNode;
	newNode->next = ptr;
	printf("Insertion Success.\n\n");
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
		printf("3. Insert at the beginning\n");
		printf("4. Insert at the end\n");
		printf("5. Insert before\n");
		printf("6. EXIT\n");
		
		printf("\nEnter your option: ");
		scanf("%d",&option);		
		switch(option)
	 	{
			case 1:	createList();break;
			case 2: printList();break;
			case 3: insertBeg();break;
			case 4: insertEnd();break;
			case 5: insertBefore();break;
		}
	}while(option != 6);
	return 0;	
}
