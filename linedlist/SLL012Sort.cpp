#include <stdio.h>
#include <malloc.h>
struct node {
	int data;
	struct node *next;
};

void sll_012_sort_swapData(struct node **head){

}
int len(struct node* head)
{
	int c = 0;  
	struct node* temp = (struct node*)malloc(sizeof(struct node)); 
	temp = head;
	while (temp != NULL)
	{
		c++;
	   temp = temp->next;
	}
	return c;
}
void sll_012_sort(struct node **head){
	if (*head == NULL)return;
	int l = 1;
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp = NULL;
	temp = *head;
	while (temp->next)
	{
		temp = temp->next;
		l++;

	}
	struct node  *last = temp;
	struct node  *prev = *head;
	struct node  *pres = *head;

	for (int i = 0; i<l; i++){
		struct node  *temp = pres;
		struct node  *nxt = pres->next;
		pres = pres->next;
		if (temp->data == 0)
		{
			if (prev != temp)
			{
				prev->next = nxt;
				temp->next = *head;
				*head = temp;
				continue;
			}
			//      prev=prev->next;
			else printf("%d \n", i);
			// continue;
		}
		else if (temp->data == 2)
		{
			last->next = temp;
			temp->next = NULL;
			last = temp;
			if (temp == prev)
			{
				*head = nxt;
				prev = nxt;
			}
			else{
				prev->next = nxt;
			}

		}
		else
		{
			prev = temp;
		}
	}
	return;
}
