#include<stdio.h>
#include<stdlib.h>
int* getLeaderIndex(int *arr, int len){
	if (arr == NULL || len <= 0)return NULL;

	int index = 0, max = 0;
	for (int i = len - 1; i > 0; i--)
	{
		int   c = 0, m = i, val = arr[i];
		//	printf("%d->>> ", arr[i]);
		while (i > 0 && val >= arr[i - 1]){ c++; i--; }
		if (max <= c)
		{
			max = c;
			index = m;
		}
		//printf("%d  ", max);

	}
	int *res = (int*)malloc(sizeof(int) * 2);
	if (index == 1 && max == 0) res[0] = 0;
	else res[0] = index;
	res[1] = max;

	return res;
}