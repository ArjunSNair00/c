#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vehicle {
    char model[50];
    int year;
    float price;
};

// Comparison function for qsort - descending order by price
int compareVehicles(const void *a, const void *b) {
    struct Vehicle *v1 = (struct Vehicle *)a;
    struct Vehicle *v2 = (struct Vehicle *)b;
    if (v1->price < v2->price)
        return 1;   // v2 comes before v1
    else if (v1->price > v2->price)
        return -1;  // v1 comes before v2
    else
        return 0;   // equal price
}

// Function to accept input for vehicles
void inputVehicles(struct Vehicle vehicles[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for vehicle %d:\n", i + 1);
        printf("Model: ");
        scanf("%s", vehicles[i].model);
        printf("Year: ");
        scanf("%d", &vehicles[i].year);
        printf("Price: ");
        scanf("%f", &vehicles[i].price);
        printf("\n");
    }
}

int main() {
    struct Vehicle vehicles[10];

    inputVehicles(vehicles, 10);

    qsort(vehicles, 10, sizeof(struct Vehicle), compareVehicles);

    printf("Vehicles sorted by price (descending):\n");
    for (int i = 0; i < 10; i++) {
        printf("Model: %s, Year: %d, Price: %.2f\n",
               vehicles[i].model, vehicles[i].year, vehicles[i].price);
    }

    return 0;
}
