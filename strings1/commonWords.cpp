/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/
#include<stdio.h>
#include<malloc.h>
int len(char *str)
{
	int i = 0;
	while (str[i] != 0)i++;
	return i;
}
int  cmp(char *str1, char *str2) {
	int i;
	if (len(str1) != len(str2))return 0;
	for (i = 0; i<len(str1); i++)if (str1[i] != str2[i])return 0;
	return 1;

}
int check(char *str)
{
	for (int i = 0; str[i] != 0; i++)
	{
	
		if (str[i] == ' ')continue;
		else return 0;
	}
	return 1;

}
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL|| check(str1)|| check(str2))return NULL;
	char str3[32][32], str4[32][32];
	char **res;
	res = (char**)malloc(31 * sizeof(char*));
	int j = 0, k = 0;
	for (int i = 0; str1[i] != 0; i++)
	{
		if (str1[i] == ' ')
		{
			str3[j][k++] = '\0';
			j++;
			k = 0;
		}
		else
		{
			str3[j][k++] = str1[i];
		}

	}
	str3[j][k++] = '\0';
	int len1 = j>0 ? j + 1 : j;
	j = k = 0;
	for (int i = 0; str2[i] != 0; i++)
	{
		if (str2[i] == ' ')
		{
			str4[j][k++] = '\0';
			j++;
			k = 0;
		}
		else
		{
			str4[j][k++] = str2[i];
		}
	}
	str4[j][k++] = '\0';
	//str3[j][k++] = '\0';

	int m = 0;
	int len2 = j>0 ? j + 1 : 0;
	for (int i = 0; i<len1; i++)
	{
		for (j = 0; j<len2; j++)
		{
			if (cmp(str3[i], str4[j]))
			{
				int k = 0;
				res[m] = (char *)malloc(31 * sizeof(char));
				for (k = 0; str3[i][k] != '\0'; k++)
				{
					    
					res[m][k] = str3[i][k];
				}
				res[m][k] = '\0';
				res[m][k++] = '\0';
				//     cout<<res[m]<<endl;
				m++;
			}
		}
	}
	if (m == 0)return NULL;
	return     res;
}

