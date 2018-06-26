//	Program to evaluate postfix expression using stack

#include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 50

float stack[MAX];
int top = -1;

float PUSH(float val)
{
	if(top == MAX - 1)
		printf("Error. Stack OverFlow.\n");
	else
		stack[++top] = val;
}

float POP()
{
	if(top == -1)
		printf("Error. Stack UnderFlow!\n");
	else
		return stack[top--];
}

float evaluatePostfix(char postfix[])
{
	float a, b, value;
	int i = 0;
	while(i < (strlen(postfix) - 1))
	{
		if(isdigit(postfix[i]))
			PUSH((float)(postfix[i] - '0'));
		else
			if(postfix[i] != ' ')
			{
				b = POP();
				a = POP();
				switch(postfix[i])
				{
					case '+':	value = a + b;
								break;
					case '-':	value = a - b;
								break;
					case '*':	value = a * b;
								break;
					case '/':	value = a / b;
								break;
					case '%':	value = (int)a % (int)b;
								break;
				}
				PUSH(value);
			}
		i++;
	}
	return POP();
}

int main()
{
	char postfix[40];
	printf("Use space to seperate operators and operands\nEnter postfix expression to evaluate: ");
	fgets(postfix,MAX,stdin);			//	Preferred but give (actualStringLength + 1) on using strlen()  
	//	OR
	//gets(postfix);					//	Not preferred but give actualStringlength on using strlen()
	
	printf("\nValue of Postfix Expression: %f",evaluatePostfix(postfix));
	return 0;
}
