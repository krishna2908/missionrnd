/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have tra
nsactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int check(char *str, char*date);

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, c = 0;
	if (A == NULL || ALen <= 0 ||BLen <= 0 ||B==NULL )return NULL;
	int f = 0;
  //int len = ALen > BLen ? ALen : BLen;
	struct transaction *res = (struct transaction*)malloc(sizeof(struct transaction)*ALen);
	for (i = 0; i<ALen; i++)
	{
		for (int j = c; j < BLen;j++)
			if (check(A[i].date, B[j].date))res[c++] = A[i]; break;
	}
	if (c == 0)return NULL;
	return res;

  



}