/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int n;

/* Stack */
int stack[MAX];
int top = -1;

void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    int val = queue[front];
    front++;
    return val;
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    scanf("%d", &n);

    /* Read queue elements */
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    /* Move queue → stack */
    while(front <= rear)
    {
        push(dequeue());
    }

    /* Move stack → queue */
    while(top != -1)
    {
        enqueue(pop());
    }

    /* Print reversed queue */
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}