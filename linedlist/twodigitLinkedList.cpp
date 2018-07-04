#include <stdio.h>
#include <malloc.h>
struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
};
int convert_sll_2digit_to_int(struct twoDigitNode *head){
	if (head == NULL)return NULL;
	int res = 0;
	while (head)
	{
		int t = (head->digit1) * 10 + (head->digit2);
		res = res * 100+ t;
		head = head->next;
	}

	return res;
}
