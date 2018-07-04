/*
You have been given a string and its length .
Two letters are said to be a pair ,If they are equal and have a character in between them .

Ex : In aba ,a[0] and a[2] are pairs becuase both are 'a' and have one letter 'b' in between .

Ex: In abab , There are two pairs ,Two 'a's and ,Two 'b's .

In abbbb; there are Two pairs , (a[1],a[3]),(a[2],a[4]);

Input : String and length of string
Output : return Total number of pairs Count .

Example Input : count_pairs_wrapper("zzzaz",5);
Example Output : 2

Hint : You can use count_pairs_wrapper as a wrapper function for your original recursive function which might take
more parameters .

NOTE : Donot use any Global Variables
*/

#include "stdafx.h"

//You can use this function ,for the actual recursion .Think of similar functions for all other problems.
int count_pairs(char *str, int len){
	if (len == 0){
		if (str[0] == str[2])return 1;
		else return 0;
	}

	if (str[len] == str[len + 2]){
		len--;
		return 1 + count_pairs(str, len);
	}
	else{
		len--;
		return 0 + count_pairs(str, len);
	}
	return 0;
}

int count_pairs_wrapper(char *str,int len){
	if (len == 0)return NULL;
	return  count_pairs(str, len- 3);
	return 0;

}

