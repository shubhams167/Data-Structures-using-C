//	Program to demonstrate implementation of a stack using array

#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
}*top = NULL;

//Function to push
void PUSH()
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	printf("Enter number to push into stack: ");
	int num;
	scanf("%d",&num);
	newNode->data = num;
	if(top == NULL)
		newNode->next = NULL;
	else
		newNode->next = top;
	top = newNode;
	printf("Pushed successfully.");
}

//Function to pop
void POP()
{
	if(top == NULL)
	{
		printf("Cannot pop. Stack UnderFlow!");
		return;
	}
	struct node *ptr = top;
	top = ptr->next;
	free(ptr);
}

//Function to peek
void PEEK()
{
	if(top == NULL)
		printf("Stack Empty.");
	else
		printf("Element at top of stack is: %d",top->data);
}

//Function to display stack elements
void DISPLAY()
{
	printf("Stack: ");
	if(top == NULL)
	{
		printf("Empty");
		return;
	}
	else
	{
		struct node *ptr = top;
		while(ptr != NULL)
		{
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}
	}
}

int main()
{
	int option;
	do
	{
		printf("\n\n********MAIN MENU********\n\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. PEEK\n");
		printf("4. Display\n");
		printf("5. EXIT\n\n");
		printf("Enter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: PUSH();break;
			
			case 2: POP();break;
			
			case 3: PEEK();break;
			
			case 4: DISPLAY();break;
		}
	}while(option != 5);
	return 0;
}
