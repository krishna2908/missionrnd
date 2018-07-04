

/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/
#include "stdafx.h"
#include<stdlib.h>
void spiralPrint(int m, int n, int **a, int k, int l,int *res,int i);
int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0|| input_array==NULL) return NULL;
	int *res = (int *)malloc(sizeof(int)*rows*columns);
	int i = 0;
	spiralPrint(rows, columns, input_array, 0, 0, res, i);
	return res;
}
void spiralPrint(int m, int n, int **a, int k, int l, int *res, int idx)
{
	if (k >= m || l >= n)return;
	int i = 0;
	for (i = l; i < n; ++i)res[idx++] = a[k][i];
	k++;
	for (i = k; i < m; ++i)res[idx++] = a[i][n - 1];
	n--;
	if (k < m)
	{
		for (i = n - 1; i >= l; --i)res[idx++] = a[m - 1][i];
		m--;
	}
	if (l < n)
	{
		for (i = m - 1; i >= k; --i) res[idx++] = a[i][l];
		l++;
	}
	spiralPrint(m, n, a, k, l, res, idx);
	return;
}