/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node* create(int data)
{
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->data = data;
	nn->right = nn->left = NULL;
	return nn;
}
struct node* insert(int *arr, int s, int e)
{
	
	if (s > e)
		return NULL;

	int mid = (s + e) / 2;
	struct node *root = create(arr[mid]);
	root->left = insert(arr, s, mid - 1);
	root->right = insert(arr, mid + 1, e);
	return root;
}

struct node * convert_array_to_bst(int *arr, int len){
	if (arr==NULL || len<=0)
	    return NULL;
	return 		insert(arr, 0, len - 1);
}

