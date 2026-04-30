/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/

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

// Queue structure
struct Queue {
    struct Node** arr;
    int front, rear, size, capacity;
};

// Create queue
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->size == 0);
}

void enqueue(struct Queue* q, struct Node* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

struct Node* dequeue(struct Queue* q) {
    struct Node* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);

        // left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i >= n) break;

        // right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Right view function
void rightView(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    while (!isEmpty(q)) {
        int size = q->size;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue(q);

            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);

            if (i == size - 1) {
                printf("%d ", curr->data);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}