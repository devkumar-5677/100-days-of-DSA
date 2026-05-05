#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
typedef struct {
    int start, end;
} Interval;

// Compare function for qsort (sort by start time)
int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Min-heap functions
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

// Function to find minimum rooms
int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;

    qsort(intervals, n, sizeof(Interval), compare);

    int *heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    // Add first meeting end time
    push(heap, &size, intervals[0].end);

    for (int i = 1; i < n; i++) {
        // If room is free, reuse it
        if (heap[0] <= intervals[i].start) {
            pop(heap, &size);
        }
        // Allocate room (push end time)
        push(heap, &size, intervals[i].end);
    }

    int result = size;
    free(heap);
    return result;
}

int main() {
    Interval intervals[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int rooms = minMeetingRooms(intervals, n);
    printf("Minimum number of rooms required: %d\n", rooms);

    return 0;
}