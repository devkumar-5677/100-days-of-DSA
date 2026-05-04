#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
int search(int* inorder, int inStart, int inEnd, int target) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == target) return i;
    }
    return -1;
}
struct TreeNode* buildHelper(int* inorder, int inStart, int inEnd,
                             int* postorder, int* postIndex) {
    if (inStart > inEnd) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    root->left = root->right = NULL;
    (*postIndex)--;
    if (inStart == inEnd) return root;
    int inIndex = search(inorder, inStart, inEnd, root->val);
    root->right = buildHelper(inorder, inIndex + 1, inEnd, postorder, postIndex);
    root->left  = buildHelper(inorder, inStart, inIndex - 1, postorder, postIndex);
    return root;
}
struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return buildHelper(inorder, 0, inorderSize - 1, postorder, &postIndex);
}

void preorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);
    struct TreeNode* root = buildTree(inorder, N, postorder, N);
    preorder(root);
    return 0;
}