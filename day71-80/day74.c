#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_LEN 100
typedef struct {
    char name[MAX_NAME_LEN];
    int count;
} Candidate;

int lexicographicSmaller(const char *a, const char *b) {
    return strcmp(a, b) < 0;
}

int findCandidate(Candidate *arr, int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) return i;
    }
    return -1;
}
int main() {
    int n;
    scanf("%d", &n);
    Candidate *candidates = (Candidate *)malloc(n * sizeof(Candidate));
    int size = 0;
    char temp[MAX_NAME_LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        int idx = findCandidate(candidates, size, temp);
        if (idx == -1) {
            strcpy(candidates[size].name, temp);
            candidates[size].count = 1;
            size++;
        } else {
            candidates[idx].count++;
        }
    }
    char winner[MAX_NAME_LEN];
    int maxVotes = -1;
    for (int i = 0; i < size; i++) {
        if (candidates[i].count > maxVotes ||
            (candidates[i].count == maxVotes && lexicographicSmaller(candidates[i].name, winner))) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        }
    }
    printf("%s %d\n", winner, maxVotes);
    free(candidates);
    return 0;
}