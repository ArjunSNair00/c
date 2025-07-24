#include <stdio.h>
int main()
{
    FILE *fp;
    fp=fopen("myfile.txt","w");
    if (fp==NULL)
    {
        printf("File not found or Error opening file\n");
        return 1;
    }
    else
    {
        printf("Successfully opened file\n");
        //puts("hello");
        char s[50];
        while(1)
        {
            printf("Enter something: ");
            scanf(" %[^\n]",s);
            if (s[0] == 'z')
                break;
            else
                fprintf(fp,"%s\n",s);
        }
        //for (int i=0;i<10;i++)
        //   fprintf(fp, "No.%d\n", i);
        //fputs("bruh",fp); 
    }
    fclose(fp);
    return 0;
}