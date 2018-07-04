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
		prev = *head;
		struct node *curr = (struct node*)malloc(sizeof(struct node));;
		curr = prev->next;
		while (curr != NULL)
		{
			if (prev->num <= n && n <= curr->num)
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
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head2 == NULL && head1 == NULL)return NULL;
	node * temp1 = head1;
	node * temp2 = head2;
	struct  node * thead = (struct node*)malloc(sizeof(struct node));
	if (head1){
		thead->num = temp1->num;
		temp1 = temp1->next;
	}
	else {
		thead->num = temp2->num;
		temp2 = temp2->next;
	}
	thead->next = NULL;
	while (temp1 != NULL)
	{
		build(&thead, temp1->num);
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		build(&thead, temp2->num);
		temp2 = temp2->next;
	}
	while (thead){ printf("%d ", thead->num); thead = thead->next; }
	return thead;

}
