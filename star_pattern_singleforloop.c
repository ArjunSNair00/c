#include <stdio.h>
void main()
{
	char str[]="* * * * ";
	int len=sizeof(str)/sizeof(str[0]);
	for (int i=1;i<len;i+=2)
		printf("%.*s\n",i,str);
}