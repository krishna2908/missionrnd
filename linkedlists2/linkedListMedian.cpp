
#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
int len(struct node * head)
{
	int l = 0;
	while (head)
	{
		l++;
		head = head->next;
	}
	return l;
}
int linkedListMedian(struct node *head) {
	int l = len(head);
	printf("%d", l);
	printf("%d", l);

	if(head==NULL||l==0) return -1;
	int h = l / 2,res=0;
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp = head;
	printf("%d", l);
	if (l == 1)return temp->num;
	if (l == 2) {
		res = temp->num;
		temp = temp->next;
		res = res + temp->num;
		return res/2;
	}
	while (h>1)
	{
		h--;
		temp = temp->next;
	}
	if (l % 2 == 0){
  		res = temp->num;
		temp = temp->next;
		res =res+ temp->num;
		res /= 2;
		return res;
	}

	else
	{
		temp = temp->next;
		return temp->num;
	}
}
