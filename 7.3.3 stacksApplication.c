//	Program to convert infix expression into postfix expression

#include<stdio.h>
#include<string.h>			//	For strlen() and strcat()
#include<ctype.h>			//	For isalnum()
#define MAX 50

char stack[MAX];
int top = -1;

//	Function to push into the stack
int PUSH(char val)
{
	stack[++top] = val;
}

//	Function to pop from the stack
char POP()
{
	return stack[top--];
}

//	Function to get priority of an operator
int getPriority(char op)
{
	if(op == '(')
		return 0;
	if(op == '+' || op == '-')
		return 1;
	if(op == '/' || op == '*')
		return 2;
}

//	Function to convert infix into postfix
char *infixToPostfix(char infix[])
{
	static char postfix[40];//	Declare postfix as static otherwise after returning, postfix will get destroyed!
	int j = 0;
	for(int i = 0; i < strlen(infix); i++)
	{
		if(isalnum(infix[i]))
			postfix[j++] = infix[i];
		else
		if(infix[i] == '(')
			PUSH(infix[i]);
		else
		if(infix[i] == ')' )
		{	
			while(stack[top] != '(')
				postfix[j++] = POP();
			POP();
		}
		else
		{
			while(getPriority(infix[i]) <= getPriority(stack[top]))
			{
				postfix[j++] = POP();
			}
			PUSH(infix[i]);
		}
	}
	while(top != -1)
		postfix[j++] = POP();
	return postfix;
}

int main()
{
	cout<<"Final Result: "<<infixToPostfix("(5+3)*4");
	return 0;
}
