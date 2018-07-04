/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int max(int a, int b);
int get_height(struct node *root);
void bfs(struct node *root,int *arr, int level, int *i)
{
	if (root == NULL)return;
	int idx = (*i);
	if (level == 1){
		 
		arr[idx] = root->data;
		idx++;
		(*i) = idx;
		return;
	}
	bfs(root->right, arr, level - 1, i);
	bfs(root->left, arr, level - 1, i);
	return;
}
void fun1(int h, int *arr,struct node*root)
{
	int idx = 0;
	for (int i = 1; i <= h; i++)
		bfs(root,arr,i,&idx);
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root==NULL)
      return NULL;
	int h = get_height(root);
	int *arr = (int *)malloc(sizeof(int) * 100);
	int idx = 0;
	fun1(h, arr, root);
	return arr;
}
