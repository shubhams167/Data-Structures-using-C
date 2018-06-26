//	Program to demonstrate implementation of a stack using array

#include<stdio.h>
#define MAX 15		//Altered to change size of the stack created

int top = -1, stack[MAX];

//Function to push number into the stack
void PUSH()
{
	if(top == MAX - 1)
		printf("Cannot PUSH. Stack Overflow!");
	else
	{
		int val;
		printf("Enter number to push: ");
		scanf("%d",&val);
		top++;
		stack[top] = val;
		printf("Push successful!");
	}
}

//Function to pop number from the stack
int POP()
{
	int val;
	if(top == -1)
		printf("Cannot POP. Stack Underflow!");
	else
	{
		val = stack[top];
		top--;
		return val;
	}
}

//Function to peek into the stack
int PEEK()
{
	if(top == -1)
		printf("Stack is empty!");
	else
		printf("Value at top of the stack is: %d",stack[top]);
}

//Function to display all elements of stack
void DISPLAY()
{
	printf("Stack: ");
	if(top == -1)
		printf("Empty");
	else
		for(int i = top; i>=0; i--)
			printf("%d ",stack[i]);
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
