/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    if(n <= 0)
        return 0;

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp->next = head;

    struct node *ptr = head;

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);

    return 0;
}