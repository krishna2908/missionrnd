#include <stdio.h>
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};
int len(struct node* head);
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}
struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 0)return NULL;
	int i = 0;
	int l = len(head);
	if (K > l)return head;
	struct node *temp = head;
	struct node *next = head->next;
	while (next)
	{
		i++;
		if (i%K == 0)
		{
			struct node * t = createNodeDummy(K);
			t->next = next;
			temp->next = t;
		//	printf("%d -> %d -> %d\n", temp->num, t->num, next->num);
			temp = next;
			next = next->next;
			continue;
		}
		temp = temp->next;
		next = next->next;
	}
	i++;
	if (i%K == 0){
		struct node * t = createNodeDummy(K);
		temp->next = t;
	}
	return head;
}
