#include<stdio.h>
#include<stdlib.h>
int ap(int *arr, int i)
{
	if (arr[i + 1] - arr[i] == arr[i + 2] - arr[i + 1])return 1;
	else return 0;
}
int gp(int *arr, int i){
	float a = (float)arr[i + 1] / arr[i], b = (float)arr[i + 2] / arr[i + 1];
	if (a == b)return 1;
	return 0;
}
int * find_sequences(int *arr, int len){
	if (arr == NULL || len <= 0)return NULL;
	int *res = (int*)malloc(sizeof(int) * 6);
	for (int i = 0; i < 6; i++)res[i] = 0;
	int i = 0;
	int mark[5] = { 0 };
	for (i = 0; i < len - 2; i++)
	{
		if (ap(arr, i) && !mark[1])
		{
			if (res[0] == 0 && !mark[0]) res[0] = i; mark[0] = 1;
			res[1] = i + 2;
		}
		if (mark[0] && !ap(arr, i))mark[1] = 1;
		if (gp(arr, i))
		{

			if (res[4] == 0 && mark[4] == 0){
				res[4] = i;
				mark[4] = 1;

			}
			res[5] = i + 2;
		}
		if (ap(arr, i) && !mark[3] && mark[1])
		{

			if (res[2] == 0 && !mark[2]) res[2] = i; mark[2] = 1;
			res[3] = i + 2;
		}
		if (mark[2] && !ap(arr, i)){ mark[3] = 1; }
	}
	return res;
}
