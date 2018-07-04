/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	if (str == NULL)return  NULL;
	char *res = (char*)malloc(sizeof(char) * 10);
	int k = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] == ' ')
		{
			res[0]=NULL;
			k = 0;
			continue;
		}
		res[k++] = str[i];
	
	}
	res[k] = 0;
	return res;


}
