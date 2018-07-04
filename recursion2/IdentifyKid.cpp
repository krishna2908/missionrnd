/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B
C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<string.h>
char arr[] = { 'a', 'b', 'c' };
void  fun(int tl, int level, int val, int *idx,int *res){
	if ((*idx)<0)return;
	if (tl == level){
		(*idx)--;
		if ((*idx) == 0){
			*res = val;
			(*idx)--;
			return;
		}
		return;
	}

	if (val == 1)
	{
		fun(tl + 1, level, 1, idx,res);
		fun(tl + 1, level, 2, idx,res);
		fun(tl + 1, level, 3, idx,res);
		return;
	}
	if (val == 2)
	{
		fun(tl + 1, level, 2, idx,res);
		fun(tl + 1, level, 3, idx,res);
		fun(tl + 1, level, 1, idx,res);
		return;
	}
	if (val == 3)
	{
		fun(tl + 1, level, 3, idx,res);
		fun(tl + 1, level, 1, idx,res);
		fun(tl + 1, level, 2, idx,res);

		return;
	}
	return;
}

char identifyKid(int N, int K) {
	if (N <= 0 || K <= 0)return '\0';
	int idx = K;
	int res = 0;
	char arr[] = { 'A', 'B', 'C' };
	fun(1, N, 1, &idx,&res);
	return arr[res - 1];
}