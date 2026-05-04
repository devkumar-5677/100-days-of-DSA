/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node* insertEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct node* mergeLists(struct node* l1, struct node* l2) {
    struct node* result = NULL;
    struct node* temp = NULL;

    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data <= l2->data) {
        result = l1;
        l1 = l1->next;
    } else {
        result = l2;
        l2 = l2->next;
    }

    temp = result;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if (l1 != NULL)
        temp->next = l1;
    else
        temp->next = l2;

    return result;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    struct node* merged = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    merged = mergeLists(list1, list2);
    printList(merged);

    return 0;
}