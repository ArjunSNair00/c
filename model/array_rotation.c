#include <stdio.h>
#include <mytools.h>
#include <math.h>
int main()
{
    int n[]={1,2,3,4};
    int size=4;
    int dir=1; 
    int original_steps=1;
    printf("Array before rotating: \n");
    printarray(size,n);
    printf("\nEnter steps along with direction: ");
    scanf("%d",&original_steps);
    if (original_steps>0) dir=1; else dir=0; //0: Left, 1: Right
    original_steps=abs(original_steps);
    int steps=original_steps%size;

    for (int i=0;i<steps;i++)
    {
        if(dir)
        {
            //right rotation
            int temp=n[size-1];
            for (int i=size-2;i>=0;i--)
                n[i+1]=n[i];
            n[0]=temp;
        }
        else{
            //left rotation
            int temp=n[0];
            for (int i=0;i<size-1;i++)
                n[i] = n[i+1];
            n[size-1] = temp; 
        }
    }

    printf("\nArray after rotating by %d step to the %s: \n",original_steps,dir?"Right":"Left");
    printarray(size,n);
    return 0;
}