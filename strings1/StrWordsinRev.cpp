#include <stdio.h>
void rev(char *begin, char *end)
{
	char temp;
	while (begin < end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}
void str_words_in_rev(char *input, int len){
	char *beg = input;
	char *tmp = input; 
	while (*tmp)
	{
		tmp++;
		if (*tmp == '\0')
		{
			rev(beg, tmp - 1);
		}
		else if (*tmp == ' ')
		{
			rev(beg, tmp - 1);
			beg = tmp + 1;
		}
	} rev(input, tmp - 1);
}
