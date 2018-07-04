#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

struct charNode{
	char letter;
	struct charNode *next;
};
long long int  reverse(long long int var)
{
	long long int res = 0;
	while (var != 0)
	{
		res = res * 10 + var % 10;
		var /= 10;

	}
	return res;
}
int isDivisibleSLL(struct charNode * head, int key){
	if (head == NULL||key==0)return -1;
	char ch = '+';
	struct charNode *temp = (struct charNode*)malloc(sizeof(struct charNode));
	temp = head;
	long long int res = 0;
	while (temp)
	{
		int  c = temp->letter - '0';
		if (c >= 0 && c <= 9)res = res * 10 + c;
		else ch = temp->letter;
		temp = temp->next;
	}
	long long int fres = reverse(res);
	if (ch == '+')fres += res;
	if (ch == '-')fres = (res + fres)*(-1);
	if (ch == '*')fres = res*fres;
	if (fres%key == 0)return 1;
	else
		return 0;
}