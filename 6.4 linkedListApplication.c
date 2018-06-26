//	Program to store and add two polynomials using linked list

#include<stdio.h>

struct node
{
	int coefficient,power;
	struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;

struct node *createPolynomial(struct node *start)
{
	int n;
	struct node *newNode = (struct node *)malloc(sizeof(struct node)), *ptr = NULL;
	
	
	printf("\nEnter coefficient: ");
	scanf("%d",&newNode->coefficient); 
	printf("Enter power: ");
	scanf("%d",&newNode->power);
	n = newNode->power;
	newNode->next = NULL;
	ptr = newNode;
	start = newNode;
	
	while(--n != -1)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter coefficient: ");
		scanf("%d",&newNode->coefficient); 
		printf("Enter power: ");
		scanf("%d",&newNode->power);
		newNode->next = NULL;
		ptr->next = newNode;
		ptr = newNode;
	}
	return start;
}


void displayPolynomial(struct node *ptr)
{
	printf("\nPolynomial: ");
	while(ptr != NULL)
	{
		printf("%dx%d ",ptr->coefficient,ptr->power);
		ptr = ptr->next; 
	}
}

struct node *addPolynomials(struct node *ptr1, struct node *ptr2, struct node *start)
{
	struct node *newNode, *ptr;
	int sum,p;
	while(ptr1 != NULL && ptr2 != NULL)
	{	
		if(ptr1->power == ptr2->power)
		{
			sum = ptr1->coefficient + ptr2->coefficient;
			p = ptr1->power;
			
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->next = NULL;
			newNode->coefficient = sum;
			newNode->power = p;
			if(start == NULL)
			{
				ptr = start;
			}
			else
			{
				ptr->next = newNode;
				ptr = newNode;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else
		if(ptr1->power > ptr2->power)
		{
			p = ptr1->power;
			sum = ptr1->coefficient;
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->next = NULL;
			newNode->coefficient = sum;
			newNode->power = p;
			if(start == NULL)
			{
				ptr = start;
			}
			else
			{
				ptr->next = newNode;
				ptr = newNode;
			}	
			ptr1 = ptr1->next;
		}
		else
		if(ptr2->power > ptr1->power)
		{
			p = ptr2->power;
			sum = ptr2->coefficient;
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->next = NULL;
			newNode->coefficient = sum;
			newNode->power = p;
			if(start == NULL)
			{
				ptr = start;
			}
			else
			{
				ptr->next = newNode;
				ptr = newNode;
			}
			ptr2 = ptr2->next;	
		}
	}
	return start;	
} 
 
 
int main()
{
	int option;
	while(option != 9)
	{
		printf("\n\nMAIN MENU\n\n");
		printf("1. Enter first polynomial\n");
		printf("2. Display first polynomial\n");
		printf("3. Enter second polynomial\n");
		printf("4. Display second polynomial\n");
		printf("5. Add polynomials\n");
		printf("6. Display resultant polynomial\n");
		printf("7. Subtract polynomials\n");
		printf("8. Display resultant polynomial\n");
		printf("9. EXIT\n");		
		printf("\nEnter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:	start1 = createPolynomial(start1);break; 
		
			case 2:	displayPolynomial(start1);break;
		
			case 3:	start2 = createPolynomial(start2);break;
		
			case 4:	displayPolynomial(start2);break;		
		
			case 5:	start3 = addPolynomials(start1,start2,start3);break;
			
			case 6:	displayPolynomial(start3);break;
//		
//			case 7: start4 = subPolynomials(start1,start2);break;
//			
//			case 8:	displayPolynomial(start4);break;
		}
	}
	return 0;
}
