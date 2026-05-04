#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int sum;
    int index;
} Entry;
int longestZeroSumSubarray(int arr[], int n) {
    int size = 2 * n + 1;
    Entry* table = (Entry*)malloc(sizeof(Entry) * size);
    for (int i = 0; i < size; i++) table[i].sum = 1e9; 
    int prefix = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        if (prefix == 0) {
            if (i + 1 > maxLen) maxLen = i + 1;
        }
        int key = (prefix % size + size) % size;
        while (table[key].sum != 1e9 && table[key].sum != prefix) {
            key = (key + 1) % size;
        }

        if (table[key].sum == 1e9) {
            table[key].sum = prefix;
            table[key].index = i;
        } else {
            int len = i - table[key].index;
            if (len > maxLen) maxLen = len;
        }
    }

    free(table);
    return maxLen;
}
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", longestZeroSumSubarray(arr, n));
    return 0;
}