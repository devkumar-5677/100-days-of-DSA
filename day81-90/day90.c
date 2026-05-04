#include <stdio.h>
int isPossible(int boards[], int n, int k, int maxLen) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxLen) return 0; 
        if (total + boards[i] > maxLen) {
            painters++;
            total = boards[i];
            if (painters > k) return 0;
        } else {
            total += boards[i];
        }
    }
    return 1;
}

int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }
    printf("%d\n", minTime(boards, n, k));
    return 0;
}