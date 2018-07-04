/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node * convert_array_to_bst(int *arr, int len);
void copyinorder(struct node *root, int *arr, int *index);
struct node* insert(int *arr, int s, int e);
struct node* create(int data);
void setinorder(struct node *root, int *arr, int *index){
	if (root == NULL)return;
	setinorder(root->left, arr, index);
	root->data = arr[(*index)];
	(*index)++;

	setinorder(root->right, arr, index);
}

 void fix_bst(struct node *root){
	 if (root == NULL)return;
	 int idx = 0;
	 int *arr = (int *)malloc(sizeof(int) * 100);
	 copyinorder(root, arr, &idx);
	 for (int i = 0; i < idx; i++)
	 {
		 for (int j = i + 1; j < idx; j++)
		 {
			 if (arr[i] > arr[j])
			 {
				 int t = arr[i];
				 arr[i] = arr[j];
				 arr[j] = t;

			 }
		 }
	 }
	 int i = 0;
	 setinorder(root, arr, &i);
 return;
 }
