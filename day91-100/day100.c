#include <stdio.h>
#include <stdlib.h>

// Structure to store value + original index
typedef struct {
    int value;
    int index;
} Pair;

void merge(Pair arr[], int temp[], int count[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    Pair *tempArr = (Pair *)malloc((right - left + 1) * sizeof(Pair));

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            tempArr[k - left] = arr[j];
            rightCount++;
            j++;
        } else {
            count[arr[i].index] += rightCount;
            tempArr[k - left] = arr[i];
            i++;
        }
        k++;
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        tempArr[k - left] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        tempArr[k - left] = arr[j];
        j++;
        k++;
    }

    for (int x = left; x <= right; x++) {
        arr[x] = tempArr[x - left];
    }

    free(tempArr);
}

void mergeSort(Pair arr[], int temp[], int count[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, count, left, mid);
    mergeSort(arr, temp, count, mid + 1, right);
    merge(arr, temp, count, left, mid, right);
}

int main() {
    int arr[] = {5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Pair *pairs = (Pair *)malloc(n * sizeof(Pair));
    int *count = (int *)calloc(n, sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        pairs[i].value = arr[i];
        pairs[i].index = i;
    }

    mergeSort(pairs, temp, count, 0, n - 1);

    printf("Count of smaller elements on right:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    free(pairs);
    free(count);
    free(temp);

    return 0;
}