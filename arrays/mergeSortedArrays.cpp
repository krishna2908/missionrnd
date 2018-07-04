#include <stdio.h>
#include<conio.h>
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int old(char *a, char*b){
	for (int i = 6; i < 10; i++)
	{
		if (a[i]>b[i])return 1;
		if (a[i]< b[i])return 0;
	}
	for (int i = 3; i < 5; i++)
	{
		if (a[i]>b[i])return 1;
		if (a[i] < b[i])return 0;
	}

	for (int i = 0; i < 2; i++)
	{
		if (a[i]>b[i])return 1;
		if (a[i] < b[i])return 0;
	}
	return 2;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || ALen <= 0 || BLen <= 0 || B == NULL)return NULL;
	int i = 0, j = 0, k = 0;
	struct transaction  *res = (struct transaction*)malloc(sizeof(struct transaction) * (ALen+BLen));
	while (i < ALen && BLen)
	{
		if ( old(A[i].date,B[j].date)== 2 ){
			res[k++] = A[i++];
			res[k++] = B[j++];
		}
		if (old(A[i].date, B[j].date) == 1)
		{
			res[k++]=B[j++];
		}
		if (old(A[i].date, B[j].date) == 0)
		{
			res[k++] = A[i++];
		}
		while (i < ALen)
		{
			res[k++] = A[i++];
		}
		while (j < BLen)
		{
			res[k++] = B[j++];
		}
		return res;
	}







