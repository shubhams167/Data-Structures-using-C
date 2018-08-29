/************************************************************************************************
*	This program is an implementation a BST(Binary Search Tree) with operations such	
*	as insertion, traversal( pre-order, in-order, post-order), deletion and few options	
*	such as find largest and smallest element in the tree, height of the tree, etc		
*	are available in this menu-driven program.						
*												
*	Author: Shubham Singh									
*	Date: 11 Aug 2018									
************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/*This structure represents a node or sub-tree in the BST*/
typedef struct node
{
	int data;
	struct node *left, *right;
}NODE;

/*Function prototypes*/
NODE* insertElement(NODE *, int);
void preorderTraversal(NODE *);
void inorderTraversal(NODE *);
void postorderTraversal(NODE *);
NODE* findSmallestElement(NODE *);
NODE* findLargestElement(NODE *);
NODE* deleteElement(NODE *, int);
int countTotalNodes(NODE *);
int countInternalNodes(NODE *);
int countExternalNodes(NODE *);


/*Main function of the program*/
int main()
{
	NODE *tree = NULL, *ptr = NULL;	//Create an empty BST
	int option, val, count = 0;
	do
	{
		printf("MAIN MENU\n");
		printf("1. Insert element\n");
		printf("2. Preorder traversal\n");
		printf("3. Inorder traversal\n");
		printf("4. Postorder traversal\n");
		printf("5. Find the smallest element\n");
		printf("6. Find the largest element\n");
		printf("7. Delete element\n");
		printf("8. Count total number of nodes\n");
		printf("9. Count total number of internal nodes\n");
		printf("10. Count total number of external nodes\n");
		printf("14. Exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:		printf("Enter value to insert in BST: ");
						scanf("%d", &val);
						tree = insertElement(tree, val);
						break;
			
			case 2:		printf("Elements of tree are:\n");
						preorderTraversal(tree);
						break;

			case 3:		printf("Elements of tree are:\n");
						inorderTraversal(tree);
						break;
						
			case 4:		printf("Elements of tree are:\n");
						postorderTraversal(tree);
						break;
			
			case 5:		printf("Smallest element of tree is: %d", (findSmallestElement(tree))->data);
						break;
						
			case 6:		printf("Largest element of tree is: %d", (findLargestElement(tree))->data);
						break;	
			
			case 7:		printf("Enter value to delete from BST: ");
						scanf("%d", &val);
						tree = deleteElement(tree, val);
						break;				
			
			case 8:		printf("Total number of nodes: %d\n", countTotalNodes(tree));
						break;
			
			case 9:		printf("Total number of internal nodes: %d\n", countInternalNodes(tree));
						break;
			
			case 10:	printf("Total number of external nodes: %d\n", countExternalNodes(tree));
						break;
					
			case 14:	break; 
			
			default:	printf("Invalid option!\n");
		}
		printf("\n");
	}while(option != 14);
	return 0;
}

/**************************************************************************************************************************************
*	FUNCTION:	This function inserts an element into the BST.
*	INPUT:		This function takes two parameters i.e., a pointer of type NODE pointing to root of BST/sub-tree and an integer val.
*	OUTPUT:		This function returns pointer of type NODE pointing to root of the sub-tree/BST.
**************************************************************************************************************************************/
NODE* insertElement(NODE *tree, int val)
{
	if(tree == NULL)
	{
		tree = (NODE *)malloc(sizeof(NODE));
		tree->data = val;
		tree->left = tree->right = NULL;
	}
	else
	if(val < tree->data)
		tree->left = insertElement(tree->left, val);
	else
		tree->right = insertElement(tree->right, val);
	return tree;
}

/***************************************************************************************************************************************
*	FUNCTION:	This function uses preorder traversal algorithm to traverse the BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		none.
***************************************************************************************************************************************/
void preorderTraversal(NODE *tree)
{
	if(tree != NULL)
	{
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

/***************************************************************************************************************************************
*	FUNCTION:	This function uses inorder traversal algorithm to traverse the BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		none.
***************************************************************************************************************************************/
void inorderTraversal(NODE *tree)
{
	if(tree != NULL)
	{
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	}
}

/***************************************************************************************************************************************
*	FUNCTION:	This function uses postorder traversal algorithm to traverse the BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		none.
***************************************************************************************************************************************/
void postorderTraversal(NODE *tree)
{
	if(tree != NULL)
	{
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}

/***************************************************************************************************************************************
*	FUNCTION:	This function finds smallest element in the BST
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		This function returns pointer of type NODE pointing to the node of the smallest element of BST.
***************************************************************************************************************************************/
NODE *findSmallestElement(NODE *tree)
{
	if(tree == NULL || tree->left == NULL)
		return tree;
	else
		return findSmallestElement(tree->left);
}

/***************************************************************************************************************************************
*	FUNCTION:	This function finds largest element in the BST
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		This function returns pointer of type NODE pointing to the node of the largest element of BST.
***************************************************************************************************************************************/
NODE* findLargestElement(NODE *tree)
{
	if(tree == NULL || tree->right == NULL)
		return tree;
	else
		return findLargestElement(tree->right);
}

/***************************************************************************************************************************************
*	FUNCTION:	This function deletes an element from the BST.
*	INPUT:		This function takes two parameters i.e., a pointer of type NODE pointing to root of BST and an integer val to delete.
*	OUTPUT:		This function returns pointer of type NODE pointing to root of the BST.
***************************************************************************************************************************************/
NODE* deleteElement(NODE *tree, int val)
{
	if(tree == NULL)
		return tree;
	else 
	if(val < tree->data)
		tree->left = deleteElement(tree->left, val);
	else
	if(val > tree->data)
		tree->right = deleteElement(tree->right, val);
	else
	{
		/*When node has no child*/
		if(tree->left == NULL && tree->right == NULL)
		{
			free(tree);
			tree = NULL;
		}
		else
		/*When node has one child*/
		if(tree->left == NULL)
		{
			NODE *temp = tree;
			tree = tree->right;
			free(temp);
		}
		else
		if(tree->right == NULL)
		{
			NODE *temp = tree;
			tree = tree->left;
			free(temp);
		}
		/*When node has two childs*/
		else
		{
			NODE *temp = findSmallestElement(tree->right);
			tree->data = temp->data;
			tree->right = deleteElement(tree->right, temp->data);
		}
	}
	return tree;
}

/***************************************************************************************************************************************
*	FUNCTION:	This function counts total number of nodes in BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		This function returns number of nodes in BST.
***************************************************************************************************************************************/
int countTotalNodes(NODE *tree)
{
	if(tree == NULL)
		return 0;
	else
		return (countTotalNodes(tree->left) + countTotalNodes(tree->right) + 1);
}

/***************************************************************************************************************************************
*	FUNCTION:	This function counts total number of internal nodes in BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		This function returns number of internal nodes in BST.
***************************************************************************************************************************************/
int countInternalNodes(NODE *tree)
{
	if(tree == NULL || (tree->left == NULL && tree->right == NULL))
		return 0;
	else
		return (countInternalNodes(tree->left) + countInternalNodes(tree->right) + 1);
}

/***************************************************************************************************************************************
*	FUNCTION:	This function counts total number of external nodes in BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		This function returns number of external nodes in BST.
***************************************************************************************************************************************/
int countExternalNodes(NODE *tree)
{
	if(tree == NULL)
		return 0;
	if(tree->left == NULL && tree->right == NULL)
		return 1;
	else
		return (countExternalNodes(tree->left) + countExternalNodes(tree->right));
}

