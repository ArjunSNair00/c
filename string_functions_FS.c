#include <stdio.h>

int len(char a[])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}

void mystrcpy(char a[],char b[])
{
    int i=0;
    while (b[i]!='\0')
    {
        a[i]=b[i];
        i++;
    }
    a[i]='\0';
}

void strrev(char a[])
{
    int size=len(a);
    int i,j,temp;
    for (i=0,j=size-1;i<size/2;i++,j--)
    {
        temp=a[i]; //simple swap
        a[i]=a[j];
        a[j]=temp;
        //a[i]=a[i]^a[j]; // bitwise swap
        //a[j]=a[i]^a[j];
        //a[i]=a[i]^a[j];
        //a[i]=a[i]^a[j]^(a[j]=a[i]); //bitwise swap
        //a[i]=a[i]+a[j]-(a[j]=a[i]); //arithmetic swap
    }
}

void mystrcat(char a[],char b[])
{
    int i,n=len(a);
    for (i=0;b[i]!='\0';i++)
    {
        a[i+n]=b[i];
    }
    a[i+n]='\0';
}

void slice(char s[], int a, int b, char result[]) {
    int j = 0;
    for (int i = a; i < b && s[i] != '\0'; i++) {
        result[j++] = s[i];
    }
    result[j] = '\0';
}

void uppercase(char a[])
{
    for (int i=0;a[i]!='\0';i++)
        if (a[i] >= 'a' && a[i] <='z')
            a[i]=a[i]-32;
}

void lowercase(char a[])
{
    for (int i=0;a[i]!='\0';i++)
        if (a[i] >= 'A' && a[i] <='Z')
            a[i]=a[i]+32;
}

int main()
{
    char a[]="Artifical";
    char b[]="Intelligence";
    char c[]="eleCtronics";
    char d[]="CoMpuTERSCIENCE";
    char sliced[30];
    printf("\nLength of string \"%s\": %d\n",a,len(a));
    
    printf("String concatenation: %s + %s = ",a,b);
    mystrcat(a,b);
    printf("%s\n",a);

    printf("String Reverse of \"%s\": ",b);
    strrev(b);
    printf("%s\n",b);

    printf("String copy of b=\"%s\" to a=\"%s\": ",b,a);
    mystrcpy(a,b);
    printf("%s\n",a);

    slice(b,0,4,sliced);
    printf("The String \"%s\" Sliced from index [0:4] = %s\n",b,sliced);

    printf("Uppercase of \"%s\": ",c);
    uppercase(c);
    printf("%s\n",c);

    printf("Lowercase of \"%s\": ",d);
    lowercase(d);
    printf("%s\n",d);
    return 0;
}