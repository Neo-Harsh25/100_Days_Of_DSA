/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int x) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = x;
}

int dequeue(Queue *q) {
    int x = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return x;
}

// Kahn's Algorithm
void topologicalSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};

    // Step 1: Calculate in-degrees
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Initialize queue with 0 in-degree nodes
    Queue q;
    initQueue(&q);

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int count = 0;
    int topo[MAX];

    // Step 3: Process queue
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        topo[count++] = node;

        for (int j = 0; j < V; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(&q, j);
                }
            }
        }
    }

    // Step 4: Check cycle
    if (count != V) {
        printf("Cycle detected. Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    int V = 6;

    // Adjacency matrix
    int adj[MAX][MAX] = {0};

    // Edges
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V, adj);

    return 0;
}