#include <stdio.h>
#include <stdlib.h>

// Node for linked list (for buckets)
struct Node {
    float value;
    struct Node* next;
};

// Insert node in sorted order (for each bucket)
void sortedInsert(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Bucket sort function
void bucketSort(float arr[], int n) {
    // Step 1: Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // bucket index
        sortedInsert(&buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->value;
            temp = temp->next;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}