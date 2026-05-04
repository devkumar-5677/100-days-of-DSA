/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

int getLength(struct node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void findIntersection(struct node* head1, struct node* head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    if(len1 > len2)
    {
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    }
    else
    {
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data == ptr2->data)
        {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

int main()
{
    int n, m;

    scanf("%d", &n);
    struct node* head1 = createList(n);

    scanf("%d", &m);
    struct node* head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}