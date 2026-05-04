/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    front = front->next;
    free(temp);

    if(front == NULL)
        rear = NULL;
}

void display()
{
    struct node *temp = front;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, x;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    display();

    return 0;
}