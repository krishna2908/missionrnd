#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};
int fact(int f)
{
	return f == 0 ? 1 : f*fact(f - 1);
}
int  fun(char *s, int n)
{
	int ans = 1;
	int arr[10] = { 0 };
	int len = n - 1;
	for (int i = 0; i < n; i++)arr[s[i] - '0']++;
	int res = 1;
	for (int i = 0; i<10; i++)res *= fact(arr[i]);
	for (int i = 0; i < n; i++) {
		int temp = 0;
		int c = 1;
		char ch = s[i];
		for (int j = 0; j < ch - '0'; j++) 
			temp += arr[j];
		for (int j = 0; j < 10; j++)
			c = (c * fact(arr[j]));
		arr[ch - '0']--;
		ans = ans + (temp * ((fact(len)) / c));
		len--;
	}
	return  (fact(n) / res) - ans + 1;
}
int doorstoCross(struct passKeyNode *passKeyHead)
{
	struct passKeyNode *temp = passKeyHead;
	if (temp == NULL)return -1;
	char str[15];
	int i = 0;
	while (temp)
	{
		str[i++] = temp->num+'0';
		temp = temp->next;
	}
	str[i] = '\0';
	return fun(str, strlen(str));
}
	       