#include <stdio.h>
int main()
{
    int id;
    char name[30],status;
    float basic_pay;
    printf("Enter employee id: ");
    scanf("%d",&id);
    printf("Enter employee name: ");
    scanf(" %[^\n]",name);
    printf("Enter status: ");
    scanf(" %c",&status);
    printf("Enter basic pay: ");
    scanf("%f",&basic_pay);
    if (status=='f'||status=='F')
        printf("Total Salary: Rs.%.2f",basic_pay+0.75*basic_pay+0.1*basic_pay);
    else if (status=='p'||status=='P')
        printf("Total Salary Rs.%.2f",basic_pay);
    else
        printf("Invalid Status");
    return 0;
}