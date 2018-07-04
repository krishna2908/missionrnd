#include <stdio.h>
#include <malloc.h>
int len(struct node* head);
struct node {
	int num;
	struct node *next;
};
void build(struct node** head, int n)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->num = n;
	temp->next = NULL;
	if (*head == NULL || (*head)->num >= n)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		struct node *prev = (struct node*)malloc(sizeof(struct node));
		//prev=NULL;
		prev = *head;
		struct node *curr = (struct node*)malloc(sizeof(struct node));;
		//curr = NULL;
		curr=prev->next;
		while (curr != NULL)
		{
			if (prev->num < n && n < curr->num)
			{
				prev->next = temp;
				temp->next = curr;
				return;
			}
			prev = prev->next;
			curr = curr->next;
		}
		prev->next = temp;
		temp->next = curr;
	}
}
struct node * sortLinkedList(struct node *head) {
	int l = len(head);
	if (l == 1)return head;
	if (head == NULL)	return NULL;
	struct node  *temp =(struct node*)malloc(sizeof(struct node));
//	temp = NULL;
	temp = head;
	struct  node * thead = (struct node*)malloc(sizeof(struct node));
	//thead = NULL;
	thead->num= temp->num;
	 thead->next=NULL;
	 temp = temp->next;
	 while (temp != NULL)
	{
		build(&thead, temp->num);
		temp = temp->next;
	}
	return thead;
}
