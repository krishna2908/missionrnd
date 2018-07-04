/* 

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/
#include <malloc.h>
#include<iostream>
struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};

int verify(bool *arr,char *pix, char ch , int x, int y, int m, int n)
{
	if (x < m && y >= 0 && !arr[x*n + y] && x >= 0 && y < n  && pix[x*n+y]==ch)return 1;
	else return 0;
}
void select(char *pixels, int m, int n, struct  result* res, int x,int y,char ch,int *idx) {
	if (verify(res->visited, pixels, ch, x, y, m, n) == 0)return;
	res->visited[x*n + y] = true;
	res->size = res->size+1;
	res->selected[*idx].x = x;
	res->selected[*idx].y = y;
	(*idx)++;
	select(pixels, m, n, res, x - 1, y, ch, idx);
	select(pixels, m, n, res, x, y - 1, ch, idx);
	select(pixels, m, n, res, x+1, y, ch, idx);
	select(pixels, m, n, res, x, y+1, ch, idx);
	return;
}
struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {
	result res;
	res.selected = (Point*)malloc(sizeof(Point)*(n+1)*(m+1));
	res.visited = (bool*)malloc(sizeof(bool)*(m+1)*(n+1));
	res.size = 0;
	if (m < 0 || n < 0 || pivot.x < 0 || pivot.y < 0 || pixels == NULL)return res;
	m++;
 	n++;
	int x = pivot.x;
	int y = pivot.y;
	int k = 0;
	char ch = pixels[n*x + y];
	for (int i = 0; i < m*n; i++)
		  res.visited[i] = false;
	res.visited[0] = false;
	select(pixels, m, n, &res, x, y,ch,&k);
	return res;
}