#include <stdio.h>
int main()
{
    int pos=0;
    for (pos;pos<=100;pos++)
    {
    printf("The element is found at %d%s position",pos,pos==0? "th" : (pos==1? "st" : (pos==2? "nd" : (pos==3? "rd" : "th"))));
    printf("\n");
    }
    return 0;
}