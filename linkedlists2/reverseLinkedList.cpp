#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if(head==NULL)return NULL;
	struct node * temp = head;
	struct node *next = (struct node*)malloc(sizeof(struct node));
	struct node *prev = NULL;
	while (temp)
	{	
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	return prev;
}
