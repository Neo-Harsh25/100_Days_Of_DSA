/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue for level order building
typedef struct {
    Node* arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* n) {
    q->arr[q->rear++] = n;
}

Node* dequeue(Queue* q) {
    return q->arr[q->front++];
}

// Create new node
Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Queue q;
    initQueue(&q);

    Node* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        Node* curr = dequeue(&q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// For vertical traversal
typedef struct {
    Node* node;
    int hd; // horizontal distance
} Pair;

typedef struct {
    Pair arr[MAX];
    int front, rear;
} PQueue;

void initPQueue(PQueue* q) {
    q->front = q->rear = 0;
}

void penqueue(PQueue* q, Node* n, int hd) {
    q->arr[q->rear].node = n;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

Pair pdequeue(PQueue* q) {
    return q->arr[q->front++];
}

int pempty(PQueue* q) {
    return q->front == q->rear;
}

// Vertical Order Traversal
void verticalOrder(Node* root) {
    if (!root) return;

    int map[MAX][MAX]; // store nodes
    int count[MAX] = {0};

    int offset = MAX / 2;

    PQueue q;
    initPQueue(&q);

    penqueue(&q, root, 0);

    while (!pempty(&q)) {
        Pair p = pdequeue(&q);
        Node* curr = p.node;
        int hd = p.hd + offset;

        map[hd][count[hd]++] = curr->data;

        if (curr->left)
            penqueue(&q, curr->left, p.hd - 1);
        if (curr->right)
            penqueue(&q, curr->right, p.hd + 1);
    }

    // print from leftmost to rightmost
    for (int i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}