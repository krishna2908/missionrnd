#include <stdio.h>
#include <stdlib.h>
struct ListNode{
	int val;
	struct ListNode *next;
};
int len(struct ListNode * head)
{
	int l = 1;
	struct ListNode *temp = head;

	temp = head;
	while (temp)
	{
		l++;
		temp = temp->next;
	}
	return l;
}
void pairUp(struct ListNode *head){
	if (head == NULL)return ;
 	ListNode * temp = head;
	ListNode * prev = head;
	int l = len(head);
	int h = l / 2;
	int *arr = (int *)malloc(sizeof(int) *l);
	int i = 0;
	while (prev)
	{
		arr[i] = prev->val;
		i++;
		prev = prev->next;
	}
	int s = 0;
	l--;
	while (temp)
	{
		temp = temp->next;
		if (temp){
			l--;
			temp->val = arr[l];
		}
		else break;
		temp = temp->next;

		if (temp){
			s++;
			temp->val = arr[s];
		}
		else break;
	}
}