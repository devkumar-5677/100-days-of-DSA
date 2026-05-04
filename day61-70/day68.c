#include <stdlib.h>
#include <string.h>
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int* result = (int*)malloc(numCourses * sizeof(int));
    int resultIdx = 0;
    struct Node {
        int val;
        struct Node* next;
    };
    struct Node** adj = (struct Node**)calloc(numCourses, sizeof(struct Node*));

    for (int i = 0; i < prerequisitesSize; i++) {
        int dest = prerequisites[i][0];
        int src = prerequisites[i][1];
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = dest;
        newNode->next = adj[src];
        adj[src] = newNode;
        
        inDegree[dest]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    while (head < tail) {
        int u = queue[head++];
        result[resultIdx++] = u;

        struct Node* curr = adj[u];
        while (curr != NULL) {
            int v = curr->val;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                queue[tail++] = v;
            }
            curr = curr->next;
        }
    }

    for (int i = 0; i < numCourses; i++) {
        struct Node* curr = adj[i];
        while (curr) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(adj);
    free(inDegree);
    free(queue);

    if (resultIdx == numCourses) {
        *returnSize = numCourses;
        return result;
    } else {
        *returnSize = 0;
        free(result);
        return NULL;
    }
}