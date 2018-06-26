//	Program to check expression validity using stack

#include<stdio.h>
#include<string.h>
#define MAX 30		//Altered to change size of the stack created

int top = -1; 
char stack[MAX];

//Function to push into the stack
void PUSH(char c)
{
	if(top == MAX - 1)
		printf("Stack Overflow.");
	else
	{
		top++;
		stack[top] = c;
	}
}

//Function to pop from the stack
char POP()
{
	if(top == -1)
		printf("Stack UnderFlow.");
	else
		return (stack[top--]);
}

int main()
{
	char str[20],temp;
	int flag = 1;
	printf("Enter expression to check validity: ");
	scanf("%s",str);
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			PUSH(str[i]);
		}
		if(str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if(top == -1)
			{
				flag = 0;
				break;
			}
			else
			{
				temp = POP();
				if(temp == '(' && (str[i] == '[' || str[i] == '{'))
					flag = 0;
				if(temp == '{' && (str[i] == '[' || str[i] == '('))
					flag = 0;
				if(temp == '[' && (str[i] == '(' || str[i] == '{'))
					flag = 0;
			}
		}
	}
	if(flag && top == -1)
		printf("Valid Expression");
	else
		printf("Invalid Expression");
	return 0;
}
