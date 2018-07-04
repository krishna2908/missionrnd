#include <stdlib.h>
#include <stdio.h>
struct node{
	int data;
	struct node *next;
};
void con(struct node** head, int n)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->next = NULL;
	if (*head == NULL || (*head)->data >= n)
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
			if (prev->data <= n && n <= curr->data)
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
struct node * merge(struct node *head1, struct node *head2) {
	if (head2 == NULL && head1 == NULL)return NULL;
	node * temp1 = head1;
	node * temp2 = head2;
	struct  node * thead = (struct node*)malloc(sizeof(struct node));
	if (head1){
		thead->data = temp1->data;
		temp1 = temp1->next;
	}
	else {
		thead->data = temp2->data;
		temp2 = temp2->next;
	}
	thead->next = NULL;
	while (temp1 != NULL)
	{
		con(&thead, temp1->data);
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		con(&thead, temp2->data);
		temp2 = temp2->next;
	}
	return thead;

}


int merge_circularlists(struct node **head1, struct node **head2){
	if (*head1 == NULL || *head2 == NULL)return -1;
	struct node *thead1 = *head1;
	struct node *thead2 = *head2;
	int c1 = 1, c2 = 1;
	while (thead1->next != *head1)

	{
		thead1 = thead1->next;
		c1++;
	}
	thead1->next = NULL;
	while (thead2->next != *head2)
	{
		thead2 = thead2->next;
		c2++;
	}
	thead2->next = NULL;
	struct node *tmp1 = *head1;
	struct node *tmp2 = *head2;
	struct node *res = merge(tmp1, tmp2);
	 *head1 = res;
	int c = 0;
	while (res->next)
	{
		res = res->next;
		c++;
	}
	res->next = *head1;
	return c1+c2;
}

