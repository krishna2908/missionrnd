#include <stdio.h>
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};
void insert(node **head, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node) * 1);
	temp->num = data;
	temp->next = *head;
	*head = temp;
}

struct node * numberToLinkedList(int N) {
	if (N == 0){
		struct node *root = (struct node *)malloc(sizeof(struct node));
		root->num = 0;
		root->next = NULL;
		return root;
	}
	if (N < 0)N *= (-1);
	struct node *root=(struct node*)malloc(sizeof(struct node));
	root = NULL;
	while (N != 0)
	{
		int num = N % 10;
		N /= 10;
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		if (root == NULL)
		{
			temp->num = num;
			temp->next = NULL;
			root = temp;
			continue;
		}
		temp->num = num;
		temp->next = root;
		root = temp;
	}
	return root;
}