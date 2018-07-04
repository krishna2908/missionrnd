#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
int square(int n)
{
	int sum = 0;
	while (n)
	{
		sum += (n % 10) * (n % 10);
		n /= 10;
	}
	return sum;
}
int happy(int n)
{
	if (n == 2 || n == 0)return 0;
	bool mark[401] = { 0 };
	while (1)
	{
		n = square(n);
		if (n == 1)
			return 1;
		if (mark[n] == 1)
			return 0;
		mark[n] = 1;
	}
}
int* getSquareLeaderArray(int *arr, int len, int *leadersArrayLen){

	if (arr == NULL || len <= 0)return NULL;
	int *res = (int*)malloc(sizeof(int)*len);
	int k = 0;
	for (int i = 0; i<len; i++)
	{
		if (happy(arr[i]) == 1){
			res[k] = arr[i];
			k++;
			// printf("%d ",arr[i]);

		}
	}
	*leadersArrayLen = k;
//	for (int i = 0; i<10; i++)printf("%d ", res[i]);
	return res;


}
