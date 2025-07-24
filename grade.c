#include <stdio.h>
int main()
{
	int mark;
	printf("Enter marks: ");
	scanf("%d",&mark);
	if (mark>75)
		printf("First class");
	if (mark>65 && mark<=75)
		printf("Second class");
	if (mark>55 && mark<=65)
		printf("Third class");
	if (mark<=55)
		printf("Fail");
	return 0;
}