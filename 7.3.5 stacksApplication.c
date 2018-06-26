//	Program to convert infix expression into postfix expression

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 50

char stack[MAX],temp_stack[MAX];
int top = -1,temp_top = -1;

void push(char stack[], char ch)
{
	if(top == MAX - 1)
		printf("Stack Overflow!");
	else
		stack[++top] = ch;
}

char pop(char stack[])
{
	if(top == -1)
		printf("Stack UnderFlow!");
	else
		return stack[top--];
}

void reverse(char *ptr, int n)
{
	for(int i = 0, i < n; i++)
	{
		temp_stack[++temp_top] = ptr[i];
	}
	for(int i = 0, i < n; i++)
	{
		temp_stack[++temp_top] = ptr[i];
	}
}

int main()
{
	char infix[40];
	printf("Enter infix expression: ");
	scanf("%s",infix);
	reverse(infix, strlen(infix));
}
