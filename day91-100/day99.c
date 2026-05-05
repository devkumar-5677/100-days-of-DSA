#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int position;
    int speed;
} Car;

// Compare function: sort by position descending
int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

int carFleets(int target, int position[], int speed[], int n) {
    Car *cars = (Car *)malloc(n * sizeof(Car));

    // Combine position & speed
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double prevTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > prevTime) {
            // New fleet
            fleets++;
            prevTime = time;
        }
        // else: joins previous fleet
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    int result = carFleets(target, position, speed, n);
    printf("Number of car fleets: %d\n", result);

    return 0;
}