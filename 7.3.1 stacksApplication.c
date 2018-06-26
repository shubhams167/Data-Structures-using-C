//	Program to reverse a string using stacks

#include<stdio.h>
#include<string.h>
#define MAX 50


char stack[MAX];
int top = -1;

void push(char ch)
{
	if(top == MAX - 1)
		printf("Error. Stack Full\n");
	else
		stack[++top] = ch;
}

char pop()
{
	if(top == -1)
		printf("Error. Stack Empty\n");
	else
		return stack[top--];
}

int main()
{
	char str[MAX];
	printf("Enter string to reverse: ");
	fgets(str,MAX,stdin);
	for(int i = 0; i < strlen(str); i++)
		push(str[i]);
	for(int i = 0; i < strlen(str); i++)
		str[i] = pop();
	printf("%s",str);
	return 0;
}
