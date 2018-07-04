#include <stdio.h>
char* rev(char * str)
{
	int n = 0;
	while (str[n] != 0){ n++; }
	for (int i = 0; i < n / 2; i++)
	{
		char ch = str[n - i - 1];
		str[n - i - 1] = str[i];
		str[i] = ch;
	}
	return str;
}
void number_to_str(float number, char *str, int afterdecimal){
	int i = 0,c=0;
	if (number < 0.0){
		c = 1;
		number *= -1;
	}
	int n = number;
	afterdecimal = 0;
	int rem = 0;
	while (n / 10 != 0){
		rem = n % 10;
		n /= 10;
		str[i++] = rem + '0';
	}
	str[i++] = n + '0';
	if(c)str[i++] ='-';

	str[i] = '\0';
	str = rev(str);
	float f = number - (int)number;
	if (f != 0.0){
		str[i++] = '.';
		while (f*10.0 != 0.0&&i<19)
		{
			afterdecimal++;
			f *= 10.0;
			str[i++] = (int)f + '0';
			f = f - (int)f;
		}
		str[i++] = '\0';
	}
	else afterdecimal = 1;
}