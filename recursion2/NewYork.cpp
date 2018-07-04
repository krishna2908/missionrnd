/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2

(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/

#include <stdio.h>
#include <stdlib.h>
#define r 1
#define l 2
#define d 3 
#define u 4
int valid(int n, int m, int x, int y)
{
	if (x<0 || y<0 || x>=n || y>=m)return 0;
	else return 1;
}
int newyork_recur(int n, int m, int x, int y, int K, int dir) {
	if (valid(n, m, x, y) == 0 || K<0)return 0;
	if (x == n - 1 && y == m - 1 && K==0)return 1;
	if (x == n - 1 && y == m - 1 && K!=0)return 0;
  	return newyork_recur(n, m, x, y + 1, K-(dir!=r), r) + newyork_recur(n, m, x, y - 1, K - (dir!=l), l) + newyork_recur(n, m, x - 1, y, K - (dir!=u), u) + newyork_recur(n, m, x + 1, y, K-(dir!=d), d);
}

int NewYork(int n, int m, int k){
	if (m <= 0 || n <= 0 || k <= 0)return 0;
	return newyork_recur(n, m, 0, 0, k + 1, 0);
}