/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50 
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    scanf("%d", &n);
    
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
    
    int count = 0;
    temp = head;
    
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    printf("%d", count);
    
    return 0;
}