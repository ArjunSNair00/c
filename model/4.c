#include <stdio.h>
#include <string.h>
int main()
{
    char names[3][20]={"Alice","Bob","Charlie"};
    char name[20];
    for (int m=0;m<3;m++)
    {
        for (int n = 0; names[m][n] != '\0'; n++) 
        {
            printf("%c", names[m][n]);
        }
        printf("\n");
    }
    printf("%d\n",strlen(names[0]));
    printf("%s",strcpy(name,names[1]));
    char a[10]="chad";
    char b[5]="chad";
    printf("\nThey are %ssame\n",strcmp(a,b)?"not ":"");
    strcat(a,b);
    printf("%s\n",a);

    char str1[]="Concatenate";
    char substr1[]="cat";
    char *ptr=strstr(str1,substr1);
    if (ptr!=NULL)
        printf("Element is found in string at index %d\n",ptr-str1); //difference between pointer gives number of elements between them (3-0)
    else
        printf("Element is not found");

    printf("%d",ptr-str1); //print index value of occurence
    printf("\n%s",ptr); //print matched substring
    printf("\n%d",*ptr); //prints value at pointer 99 is ascii value of 'c'
    printf("\n%ld",ptr); //prints address of pointer in decimal
    printf("\n%p",ptr); //prints address of pointer in hexadecimal
    printf("\n%p", (void *)ptr); //prints address of pointer in hexadecimal

    printf("\n");
    printf("Enter names: \n");
    char arrr[3][20];
    for (int m=0;m<3;m++)
    {
        fgets(arrr[m],20,stdin);
    }

    printf("\n");
    for (int m=0;m<3;m++)
        printf("%s", arrr[m]);
    return 0;
}