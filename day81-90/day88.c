#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1;
    int lastPos = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count == k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }
    qsort(stalls, n, sizeof(int), compare);
    int low = 1, high = stalls[n - 1] - stalls[0], result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", result);
    return 0;
}