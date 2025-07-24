#include <stdio.h>
struct Date {
    int day, month, year;
};
int compareDates(struct Date datel, struct Date date2) {
    if (datel.year < date2.year) 
        return 1; // datel is earlier
    else if(datel.year > date2.year) 
        return 0; // datel is later
    if (datel.month < date2.month) 
        return 1; // datel is earlier
    else if(datel.month > date2.month) 
        return 0; // datel is later
    if (datel.day < date2.day) 
        return 1; // date1 is earlier
    else if(datel.day > date2.day) 
        return 0; // datel is later
    return -1; // Both dates are same
}
int main() {
    struct Date datel, date2;
    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &datel.day, &datel.month, &datel.year);
    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);
    int result = compareDates (datel, date2);
    if (result == 1) 
        printf("Datel is earlier than Date2\n");
    else if(result == 0) 
        printf("Datel is later than Date2\n");
    else 
        printf("Both dates are the same\n");
    return 0;
}