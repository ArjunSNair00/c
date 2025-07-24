#include <stdio.h>
int main()
{
    float x,y;
    printf("Enter the coordinates (x,y): ");
    scanf("%f %f",&x,&y);
    if (x!=0 && y==0)
        printf("X-Axis");
    else if (x==0 && y!=0)
        printf("Y-Axis");
    else if (x>0 && y>0)
        printf("First Quadrant");
    else if (x<0 && y>0)
        printf("Second Quadrant");
    else if (x<0 && y<0)
        printf("Third Quadrant");
    else if (x>0 && y<0)
        printf("Fourth Quadrant");
    else
        printf("Origin");
    return 0;
}