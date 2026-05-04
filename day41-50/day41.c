/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure */
struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

/* Enqueue operation */
void enqueue(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

/* Dequeue operation */
int dequeue()
{
    if (front == NULL)
        return -1;

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);

    return value;
}

/* Main function */
int main()
{
    int n;
    scanf("%d", &n);

    char op[20];
    int value;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &value);
            enqueue(value);
        }
        else if (strcmp(op, "dequeue") == 0)
        {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}