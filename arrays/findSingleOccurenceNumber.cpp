/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>

void merge(int *A, int start, int mid, int end) {
	int p = start, q = mid + 1;
	//int *Arr=(int*)malloc(sizeof(int)*(end - start + 1)), k = 0;
	int Arr[1005], k = 0;
	for (; k<end - start + 1;) {
		if (p > mid)Arr[k++] = A[q++];
		else if (q > end)   Arr[k++] = A[p++];

		else if (A[p] <= A[q])Arr[k++] = A[p++];

		else  Arr[k++] = A[q++];
	}
	for (int p = 0; p< k; p++) A[start++] = Arr[p];
	//	free(Arr);
}
void mergeSort(int *arr, int l, int r)
{
	if (r>l)
	{
		int mid = l + (r - l) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len <= 0)return -1;
	mergeSort(A, 0, len);
	int i = 0;
	for (i = 0; i < len-2; i ++)
	{
		if (A[i] != A[i + 2])return A[i];
             else	i+=2;
	}
	return A[len-1];
}