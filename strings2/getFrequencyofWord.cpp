/*
Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/
#include <stdlib.h>

int count_word_in_str_way_1(char *str, char *word){
	int c = 0, idx = 0, len = 0;
	if (str == NULL || word == NULL)return 0;

	while (word[len] != 0)len++;
	for (int j = 0; str[j] != '\0';)
	{
		if (word[idx] != 0 && str[j] == word[idx])
		{
			idx++;
			j++;
			if (idx == len){
				c++;
				j = j - len + 1;
				idx = 0;

			}

			continue;
		}
		idx = 0; j++;
	}
	return c;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

