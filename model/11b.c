#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct City {
    char name[50];
    float literacy;
    int population;
};

int compareCities(const void *a, const void *b) {
    struct City *cityA = (struct City *)a;
    struct City *cityB = (struct City *)b;

    // Compare by name (lexicographically)
    int nameComparison = strcmp(cityA->name, cityB->name);
    if (nameComparison != 0)
        return nameComparison;

    // Compare by literacy (higher first)
    if (cityA->literacy < cityB->literacy)
        return 1;
    else if (cityA->literacy > cityB->literacy)
        return -1;

    // Compare by population (higher first)
    if (cityA->population < cityB->population)
        return 1;
    else
        return -1;
}

int main() {
    struct City cities[100];
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter city %d details:\n", i + 1);
        printf("City Name: ");
        scanf("%s", cities[i].name);

        printf("Literacy Level: ");
        scanf("%f", &cities[i].literacy);

        printf("Population: ");
        scanf("%d", &cities[i].population);
    }

    // Sort the cities
    qsort(cities, n, sizeof(struct City), compareCities);

    // Display sorted cities
    printf("\nCities sorted lexicographically, then by literacy, and then by population:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %.2f %d\n", cities[i].name, cities[i].literacy, cities[i].population);
    }

    return 0;
}
