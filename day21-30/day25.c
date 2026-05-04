#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, key;

    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &key);
    int result = countOccurrences(head, key);

    printf("%d", result);

    return 0;
}