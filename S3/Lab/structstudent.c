#include <stdio.h>

struct student 
{
    char name[30];
    int rollno;
    float marks[3];
};

int main() 
{
    int n;
    char *subjects[] = {"Maths", "DSA", "Data Science"};
    int sub_num = sizeof(subjects) / sizeof(subjects[0]);
    //char subjects[3][20] = {"Maths", "DSA", "Data Science"};
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for (int i = 0; i < n; i++) 
    {
        s[i].rollno = i + 1;
        printf("\nRoll number: %d\n", s[i].rollno);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter marks for: \n");
        for (int j = 0; j < sub_num; j++) 
        {
            printf("%s: ", subjects[j]);
            scanf("%f", &s[i].marks[j]);
        }
    }
    printf("\nThe Student Details are: ");
    for (int i = 0; i < n; i++) 
    {
        printf("\n\nRoll number: %d", s[i].rollno);
        printf("\nName: %s", s[i].name);
        for (int j = 0; j < sub_num; j++) 
        {
            printf("\n%s: %g", subjects[j], s[i].marks[j]);
        }
    }

    return 0;
}
