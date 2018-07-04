/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void copyinorder(struct node *root, int *arr, int *index){
	if (root == NULL)return;
	copyinorder(root->left, arr,index);
	arr[(*index)] = root->data;
	(*index)++;

	copyinorder(root->right, arr,index);
}
void copypreorder(struct node *root, int *arr, int *index){
	if (root == NULL)return;
	arr[(*index)] = root->data;
	(*index)++;
	copypreorder(root->left, arr,index);
	copypreorder(root->right, arr,index);

}
void copypostorder(struct node *root, int *arr, int *index){
	if (root == NULL)return;
	copypostorder(root->left, arr, index);
	copypostorder(root->right, arr, index);
	arr[(*index)] = root->data;
	(*index)++;

}


void inorder(struct node *root, int *arr){
	
	 if (root == NULL||arr==NULL)return ;
	 int i = 0;
	 copyinorder(root, arr, &i);
}
void preorder(struct node *root, int *arr){
	if (root == NULL||arr==NULL)return ;
	int i = 0;
	copypreorder(root, arr, &i);

}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr==NULL)return ;
	int i = 0;
	copypostorder(root, arr, &i);
	return;
}

