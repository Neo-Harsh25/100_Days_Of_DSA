/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Graph representation (adjacency list)
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* adj[MAX];

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct MinHeap* h, int idx) {
    while (idx && h->heap[idx].dist < h->heap[(idx - 1)/2].dist) {
        swap(&h->heap[idx], &h->heap[(idx - 1)/2]);
        idx = (idx - 1)/2;
    }
}

// Heapify down
void heapifyDown(struct MinHeap* h, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&h->heap[idx], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Push into heap
void push(struct MinHeap* h, int vertex, int dist) {
    int i = h->size++;
    h->heap[i].vertex = vertex;
    h->heap[i].dist = dist;
    heapifyUp(h, i);
}

// Pop minimum
struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapifyDown(h, 0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra function
void dijkstra(int V, int source) {
    int dist[MAX];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[source] = 0;
    push(&heap, source, 0);

    while (heap.size > 0) {
        struct HeapNode top = pop(&heap);
        int u = top.vertex;

        if (top.dist > dist[u])
            continue;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    for (int i = 0; i < V; i++)
        printf("Distance from %d to %d = %d\n", source, i, dist[i]);
}

// Example usage
int main() {
    int V = 5;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0,1,10);
    addEdge(0,4,5);
    addEdge(1,2,1);
    addEdge(4,1,3);
    addEdge(4,2,9);
    addEdge(4,3,2);
    addEdge(2,3,4);
    addEdge(3,2,6);

    dijkstra(V, 0);

    return 0;
}