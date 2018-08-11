/*
*	This program is an implementation a BST(Binary Search Tree) with operations such 
*	as insertion, traversal( pre-order, in-order, post-order), deletion and few options
*	such as find largest and smallest element in the tree, height of the tree, etc
*	are available in this menu-driven program.
*
*	author: Shubham Singh
*	Date: 11 Aug 2018
*/

#include<stdio.h>
#include<malloc.h>

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
NODE *findSmallestElement(NODE *);
NODE *findLargestElement(NODE *);

/*Main function of the program*/
int main()
{
	NODE *tree = NULL, *ptr = NULL;	//Create an empty BST
	int option, val;
	do
	{
		printf("MAIN MENU\n");
		printf("1. Insert element\n");
		printf("2. Preorder traversal\n");
		printf("3. Inorder traversal\n");
		printf("4. Postorder traversal\n");
		printf("5. Find the smallest element\n");
		printf("6. Find the largest element\n");
		printf("14. Exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:		printf("Enter value to insert in BST: ");
						scanf("%d", &val);
						tree = insertElement(tree, val);	//Insert val to BST
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
						
			case 14:	break; 
		}
		printf("\n");
	}while(option != 14);
	return 0;
}

/*
*	FUNCTION:	This function inserts an element into the BST.
*	INPUT:		This function takes two parameters i.e., a pointer of type NODE pointing to root of BST and an integer val.
*	OUTPUT:		This function returns pointer of type NODE pointing to root of the BST.
*/
NODE* insertElement(NODE *tree, int val)
{
	NODE *newTree = (NODE *)malloc(sizeof(NODE)), *node, *parentNode;
	newTree->data = val;
	newTree->left = NULL;
	newTree->right = NULL;
	if(tree == NULL)
	{
		tree = newTree;
		tree->left = NULL;
		tree->right = NULL;
	}
	else
	{
		node = tree;
		parentNode = NULL;
		while(node != NULL)
		{
			parentNode = node;
			if(node->data > val)		
				node = node->left;	//Value to be inserted is smaller than value at current node, go to left sub-tree
			else
				node = node->right;	//Value to be inserted is either greater than or equal to value at current node, go to right sub-tree
		}
		if(val < parentNode->data)	
			parentNode->left = newTree;
		else
			parentNode->right = newTree;
	}
	return tree;
}

/*
*	FUNCTION:	This function uses preorder traversal algorithm to traverse the BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		none.
*/
void preorderTraversal(NODE *tree)
{
	if(tree != NULL)
	{
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

/*
*	FUNCTION:	This function uses inorder traversal algorithm to traverse the BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		none.
*/
void inorderTraversal(NODE *tree)
{
	if(tree != NULL)
	{
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	}
}

/*
*	FUNCTION:	This function uses postorder traversal algorithm to traverse the BST.
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		none.
*/
void postorderTraversal(NODE *tree)
{
	if(tree != NULL)
	{
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}

/*
*	FUNCTION:	This function finds smallest element in the BST
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		This function returns pointer of type NODE pointing to the node of the smallest element of BST.
*/
NODE *findSmallestElement(NODE *tree)
{
	if(tree == NULL || tree->left == NULL)
		return tree;
	else
		return findSmallestElement(tree->left);
}

/*
*	FUNCTION:	This function finds largest element in the BST
*	INPUT:		This function takes one parameter i.e., a pointer of type NODE pointing to root of BST.
*	OUTPUT:		This function returns pointer of type NODE pointing to the node of the largest element of BST.
*/
NODE *findLargestElement(NODE *tree)
{
	if(tree == NULL || tree->right == NULL)
		return tree;
	else
		return findLargestElement(tree->right);
}
