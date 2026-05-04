/*Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(int value)
{
    if(value == -1)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Inorder Traversal */
void inorder(struct Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Preorder Traversal */
void preorder(struct Node* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* Postorder Traversal */
void postorder(struct Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* nodes[n];

    /* Create nodes */
    for(int i=0;i<n;i++)
        nodes[i] = createNode(arr[i]);

    /* Connect children */
    for(int i=0;i<n;i++)
    {
        if(nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    /* Print traversals */
    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}
