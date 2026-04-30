/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int cap = 1024;
    struct TreeNode** q = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * cap);
    int front = 0, rear = 0;

    q[rear++] = root;

    int resCap = 1024;
    int** res = (int**)malloc(sizeof(int*) * resCap);
    *returnColumnSizes = (int*)malloc(sizeof(int) * resCap);

    int levels = 0;

    while (front < rear) {
        int size = rear - front;

        // Resize result arrays if needed
        if (levels >= resCap) {
            resCap *= 2;
            res = (int**)realloc(res, sizeof(int*) * resCap);
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * resCap);
        }

        res[levels] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[levels] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[front++];

            res[levels][i] = node->val;

            if (node->left) {
                if (rear >= cap) {
                    cap *= 2;
                    q = (struct TreeNode**)realloc(q, sizeof(struct TreeNode*) * cap);
                }
                q[rear++] = node->left;
            }

            if (node->right) {
                if (rear >= cap) {
                    cap *= 2;
                    q = (struct TreeNode**)realloc(q, sizeof(struct TreeNode*) * cap);
                }
                q[rear++] = node->right;
            }
        }

        levels++;
    }

    *returnSize = levels;
    return res;
}