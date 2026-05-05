#include <stdio.h>
#include <stdlib.h>

// Interval structure
typedef struct {
    int start, end;
} Interval;

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

// Function to merge intervals
void mergeIntervals(Interval arr[], int n) {
    if (n == 0) return;

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Temp array to store result
    Interval *result = (Interval *)malloc(n * sizeof(Interval));
    int k = 0;

    // Step 2: Add first interval
    result[k++] = arr[0];

    // Step 3: Traverse remaining intervals
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[k - 1].end) {
            // Overlapping → merge
            if (arr[i].end > result[k - 1].end)
                result[k - 1].end = arr[i].end;
        } else {
            // Non-overlapping → add new interval
            result[k++] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged intervals:\n");
    for (int i = 0; i < k; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }

    free(result);
}

int main() {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}