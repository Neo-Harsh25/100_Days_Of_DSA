/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order construction
struct Node** queue;
int front = 0, rear = 0;

void push(struct Node* node) {
    queue[rear++] = node;
}

struct Node* pop() {
    return queue[front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    queue = (struct Node**)malloc(n * sizeof(struct Node*));

    struct Node* root = newNode(arr[0]);
    push(root);

    int i = 1;

    while (front < rear && i < n) {
        struct Node* curr = pop();

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            push(curr->left);
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            push(curr->right);
        }
        i++;
    }

    free(queue);
    return root;
}

// Mirror function
void mirror(struct Node* root) {
    if (root == NULL) return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    mirror(root);

    inorder(root);

    return 0;
}