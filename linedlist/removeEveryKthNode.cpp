#include <stdio.h>
#include <stdlib.h>
struct node {
	int num;
	struct node *next;
};
struct node * removeEveryKthNode(struct node *head, int K) {
	struct node * root = head;
	struct node * temp = root;
	struct node * prev = NULL;

	int t = 1,f=0;
	if (K <= 1||head==NULL)return NULL;
	while (root)
	{
		if (t == 1){
			prev = root;
		  	root = root->next;
			t++;
			continue;
		}
		if (t % K != 0)
		{
			t++;
			root = root->next;
	/*		if (f == 1)
			{
				f = 0;
				continue;
			}*/
			prev = prev->next;
			continue;
			}
		else
		{
			t++;
			prev->next = root->next;
//			free(root);
			//prev = prev->next;
			root = root->next;
			f = 1;
		}
	}
	return head;
}