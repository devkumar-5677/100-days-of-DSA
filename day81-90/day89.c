#include <stdio.h>
#include <limits.h>
int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) {
            return 0; 
        }

        if (sum + books[i] > maxPages) {
            students++;
            sum = books[i];

            if (students > m) {
                return 0;
            }
        } else {
            sum += books[i];
        }
    }
    return 1;
}
int allocateBooks(int books[], int n, int m) {
    if (m > n) {
        return -1; 
    }

    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        end += books[i];
    }

    int result = INT_MAX;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(books, n, m, mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int books[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    int answer = allocateBooks(books, n, m);
    printf("%d\n", answer);

    return 0;
}