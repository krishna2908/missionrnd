#include<stdio.h>
#include<stdlib.h>
int valid(int m, int n, int x, int y)
{
	if (x <0 || y <0 || x >= m || y >= n) return 0;
	else return 1;
}
int path(int *maze, int *vis, int rows, int cols, int x1, int y1, int x2, int y2)
{
	if (!valid(rows, cols, x1, y1))return 0;
	if (maze[x1*cols + y1] == 0 || vis[x1*cols + y1])return 0;
	vis[x1*cols + y1] = 1;
	if (x1 == x2 && y1 == y2)	return 1;
	if (path(maze, vis, rows, cols, x1, y1 + 1, x2, y2))return 1;
	if (path(maze, vis, rows, cols, x1, y1 - 1, x2, y2))return 1;
	if (path(maze, vis, rows, cols, x1 + 1, y1, x2, y2))return 1;
	if (path(maze, vis, rows, cols, x1 - 1, y1, x2, y2))return 1;
	else return 0;
}
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int *mark = (int*)malloc(sizeof(int)*(rows*columns));
	for (int i = 0; i < (rows*columns); i++)mark[i] = 0;
	if (path(maze, mark, rows, columns, x1, y1, x2, y2) == 1)return 1;
	else return 0;
}