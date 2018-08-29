//	Program to store and add two polynomials using linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int coefficient,power;
	struct node *next;
}NODE;

NODE* createPolynomial(NODE *poly)
{
	int n;
	NODE *newNode = NULL, *ptr = poly;
	while(1)
	{
		newNode = (NODE *)malloc(sizeof(NODE));
		printf("\nEnter coefficient: ");
		scanf("%d", &newNode->coefficient); 
		if(newNode->coefficient == -1)
		{
			free(newNode);
			break;
		}
		printf("Enter it's power: ");
		scanf("%d", &newNode->power);
		newNode->next = NULL;
		if(poly == NULL)
			poly = newNode;
		else
			ptr->next = newNode;
		ptr = newNode;
	}
	return poly;
}


void displayPolynomial(NODE *poly)
{
	printf("\nPolynomial: ");
	while(poly != NULL)
	{
		printf("%dx%d ", poly->coefficient, poly->power);
		poly = poly->next; 
	}
}
 
NODE* addPolynomial(NODE *poly1, NODE *poly2, NODE *polyAddResult)
{
	if(poly1 == NULL || poly2 == NULL)
	{
		printf("Cannot add polynomials!\n");
		return NULL;
	}
	NODE *newNode = NULL, *ptr1 = NULL, *ptr2 = NULL, *ptr3 = polyAddResult;
	
	if(poly1->power >= poly2->power)		/*Polynomial 1 has higher degree*/
	{	
		ptr1 = poly1;						/*ptr1 points to polynomial with highest degree i.e. polynomial 1*/
		ptr2 = poly2;	
	}
	else									/*Polynomial 2 has higher degree*/
	{	
		ptr1 = poly2;						/*ptr1 points to polynomial with highest degree i.e. polynomial 2*/
		ptr2 = poly1;	
	}
	
	while(ptr1 != NULL)
	{
		newNode = (NODE *)malloc(sizeof(NODE));
		newNode->next = NULL;
		if(ptr1->power == ptr2->power)
		{
			newNode->coefficient = ptr1->coefficient + ptr2->coefficient;
			newNode->power = ptr1->power;
			printf("1 %d\n", ptr1->power);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;		
		}
		else
		{
			newNode->coefficient = ptr1->coefficient;
			newNode->power = ptr1->power;
			printf("2 %d\n", ptr1->power);
			ptr1 = ptr1->next;
		}
		if(ptr3 == NULL)
			polyAddResult = newNode;
		else
			ptr3->next = newNode;
		ptr3 = newNode;
	}
	return polyAddResult;
} 
 
int main()
{
	NODE *poly1 = NULL, *poly2 = NULL, *polyAddResult = NULL, *polySubResult = NULL;
	int option;
	do
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
		scanf("%d", &option);
		switch(option)
		{
			case 1:		poly1 = createPolynomial(poly1);
						break; 
		
			case 2:		displayPolynomial(poly1);
						break;
		
			case 3:		poly2 = createPolynomial(poly2);
						break;
		
			case 4:		displayPolynomial(poly2);
						break;		
		
			case 5:		polyAddResult = addPolynomial(poly1, poly2, polyAddResult);
						break;
			
			case 6:		displayPolynomial(polyAddResult);
						break;
		
//			case 7: 	polySubResult = subPolynomials(poly1, poly2, polySubResult);break;
//			
//			case 8:		displayPolynomial(polySubResult);break;

			case 9:		break;
			
			default:	printf("Invalid input!\n");
		}
	}while(option != 9);
	return 0;
}
