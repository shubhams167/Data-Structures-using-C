//	Program to evaluate prefix expression using stack

#include<stdio.h>
#include<string.h>				//	For strlen()
#include<ctype.h>				//	For isdigit()

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

float evaluatePrefix(char prefix[])
{
	float a, b, value;
	int i = (strlen(prefix) - 2);
	while(i >= 0 )
	{
		if(isdigit(prefix[i]))
			PUSH((float)(prefix[i] - '0'));
		else
			if(prefix[i] != ' ')
			{
				a = POP();
				b = POP();
				switch(prefix[i])
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
		i--;
	}
	return POP();
}

int main()
{
	char prefix[40];
	printf("Use space to seperate operators and operands\nEnter prefix expression to evaluate: ");
	fgets(prefix,MAX,stdin);			//	Preferred but give (actualStringLength + 1) on using strlen()  
	//	OR
	//gets(postfix);					//	Not preferred but give actualStringlength on using strlen()
	
	printf("\nValue of Prefix Expression: %f",evaluatePrefix(prefix));
	return 0;
}
