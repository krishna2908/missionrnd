#include <stdio.h>
#include <stdlib.h>
int strlen(char *str)
{
	int i = 0;
	while (str[i] != 0)i++;
	return i;
}
char* oro(char *str1, char *str2)
{
	int len1 = strlen(str1) - 1, len2 = strlen(str2) - 1;
	int len = len1>len2?len1:len2;
	int i = len - 1;
	char *res = (char*)malloc(sizeof(char)*100);
	while (len1 >= 0 && len2 >= 0){
		int a = str1[len1] - '0';
		int b = str2[len2] - '0';
		int c = a | b;
		char k = c + '0';
		// cout<<k<<endl;
		res[len] = k;
		len--; len1--; len2--;
	}
	while (len1 >= 0)
	{
		res[len--] = str1[len1--];
	}
	while (len2 >= 0)
	{
		res[len--] = str1[len2--];
	}

	return res;
}
char* ando(char *str1, char *str2)
{
	int len1 = strlen(str1) - 1, len2 = strlen(str2) - 1;
	int len = len1>len2 ? len1 : len2;
	
	char *res = (char*)malloc(sizeof(char) * len+1);
	res[len + 1] = '\0';
	 while (len1 >= 0 && len2 >= 0){
		int a = str1[len1] - '0';
		int b = str2[len2] - '0';
		int c = a & b;
		char k = c + '0';
		res[len] = k;
		len--; len1--; len2--;
	}
	while (len>=0)
	{
		res[len] = '0';
		len--;
	}	
	return res;
}
char* xoro(char *str1, char *str2)
{
	int len1 = strlen(str1) - 1, len2 = strlen(str2) - 1;
	int len = len1 > len2 ? len1 : len2;
	int i = len - 1;
	char *res = (char*)malloc(sizeof(char)*(100));
	while (len1 >= 0 && len2 >= 0){

		int a = str1[len1] - '0';
		int b = str2[len2] - '0';
		int c = a^b;
		char k = c + '0';
		// cout<<k<<endl;
		res[len] = k;
		len--; len1--; len2--;

	}
	while (len1 >= 0)res[len--] = str1[len1--];
	while (len2 >= 0)res[len--] = str2[len2--];
	return res;
}
int strc(char *a, char *b)
{
	int c = 0;

	while (a[c] == b[c]) {
		if (a[c] == '\0' || b[c] == '\0')
			break;
		c++;
	}

	if (a[c] == '\0' && b[c] == '\0')
		return 1;
	else
		return 0;
}
char* noro(char *str1, char *str2)
{
	int len1 = strlen(str1) - 1, len2 = strlen(str2) - 1;
	int len = len1 > len2 ? len1 : len2;
	int i = len;
	char *res = (char*)malloc(sizeof(char)*(100));
	while (len1 >= 0 && len2 >= 0 && len >= 0){

		int a = str1[len1] - '0';
		int b = str2[len2] - '0';
		int c = !(a | b);

		char k = c + '0';
	//	cout << k << endl;
		//    cout<<len<<endl;
		res[len] = k;
		len--;
		len1--; len2--;


	}
	while (len1 >= 0)
	{
		if (str1[len1] == '1')res[len] = '0';
		if (str1[len1] == '0')res[len] = '1';
		len--;  len1--;
	}

	while (len2 >= 0)
	{
		if (str2[len2] == '1')res[len] = '0';
		if (str2[len2] == '0')res[len] = '1';
		len--; len2--;
	}
	res[i + 1] = '\0';
//	cout << res << endl;
	return res;
}
char *performOperation(char *str1, char *str2, char *operation){
	
	char *res = (char*)malloc(sizeof(char) * 100);
	if (strc(operation, "OR") == 1) res=oro(str1, str2);
	if (strc(operation, "NOR") == 1)res= noro(str1, str2);
	if (strc(operation, "XOR") == 1)res= xoro(str1, str2);
	if (strc(operation, "AND") == 1)res =ando(str1, str2);
	return res;
}








