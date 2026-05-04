/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int rear = -1;

void insert(int x)
{
    if(rear == MAX-1)
    {
        printf("Overflow\n");
        return;
    }

    rear++;
    pq[rear] = x;
}

int delete()
{
    if(rear == -1)
        return -1;

    int min = pq[0];
    int pos = 0;

    for(int i=1;i<=rear;i++)
    {
        if(pq[i] < min)
        {
            min = pq[i];
            pos = i;
        }
    }

    for(int i=pos;i<rear;i++)
        pq[i] = pq[i+1];

    rear--;

    return min;
}

int peek()
{
    if(rear == -1)
        return -1;

    int min = pq[0];

    for(int i=1;i<=rear;i++)
        if(pq[i] < min)
            min = pq[i];

    return min;
}

int main()
{
    int n,x;
    char op[10];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete")==0)
        {
            printf("%d\n",delete());
        }
        else if(strcmp(op,"peek")==0)
        {
            printf("%d\n",peek());
        }
    }

    return 0;
}