/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/
#include<stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int size;

void enqueue(int x)
{
    if((rear + 1) % size == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % size;

    queue[rear] = x;
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

void display()
{
    if(front == -1)
        return;

    int i = front;

    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % size;
    }
}

int main()
{
    int n,m,x;

    scanf("%d",&n);
    size = n;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++)
        dequeue();

    display();

    return 0;
}