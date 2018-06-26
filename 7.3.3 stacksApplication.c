//	Program to convert infix expression into postfix expression

#include<stdio.h>
#include<string.h>			//	For strlen() and strcat()
#include<ctype.h>			//	For isalpha()
#define MAX 50

char stack[MAX];
int top = -1;

//	Function to push into the stack
int PUSH(char val)
{
	if(top == MAX - 1)
		printf("Error. Stack OverFlow.\n");
	else
		stack[++top] = val;
}

//	Function to pop from the stack
char POP()
{
	if(top == -1)
		printf("Error. Stack UnderFlow!\n");
	else
		return stack[top--];
}

//	Function to get priority of an operator
int getPriority(char op)
{
	if(op == '/' || op == '*' || op == '%')
		return 1;
	else
		return 0;
}

//	Function to convert infix into postfix
char *infixToPostfix(char infix[])
{
	static char postfix[40];				//	Declare postfix as static otherwise after returning, postfix will get destroyed!
	int j = 0;
	PUSH('(');								//	To push '(' into the stack
	for(int i = 0; i < strlen(infix); i++)
	{
		if(isalpha(infix[i]))
			postfix[j++] = infix[i];
		else
			if(infix[i] == ')' )
			{	
				while(stack[top] != '(')
					postfix[j++] = POP();
				POP();
			}
			else
			{
				if(getPriority(infix[i]) < getPriority(stack[top]))
				{
					postfix[j++] = POP();
				}
				PUSH(infix[i]);
			}
	}
	return postfix;
}

int main()
{
	char infix[40];
	printf("Enter Infix expression: ");
	scanf("%s",infix);
	
	strcat(infix,")");							//	To add ')' at the end of the expression
	
	printf("\nPostfix Expression: %s",infixToPostfix(infix));
	return 0;
}
