/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

typedef struct {
    int node;
    int dist;
} HeapNode;

typedef struct {
    HeapNode arr[MAX];
    int size;
} MinHeap;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *h, int node, int dist) {
    h->size++;
    int i = h->size;
    h->arr[i].node = node;
    h->arr[i].dist = dist;

    while (i > 1 && h->arr[i].dist < h->arr[i/2].dist) {
        swap(&h->arr[i], &h->arr[i/2]);
        i /= 2;
    }
}

HeapNode pop(MinHeap *h) {
    HeapNode root = h->arr[1];
    h->arr[1] = h->arr[h->size--];

    int i = 1;
    while (1) {
        int left = 2*i, right = 2*i+1, smallest = i;

        if (left <= h->size && h->arr[left].dist < h->arr[smallest].dist)
            smallest = left;
        if (right <= h->size && h->arr[right].dist < h->arr[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = adj[u];
    adj[u] = e;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        HeapNode cur = pop(&heap);
        int u = cur.node;
        int d = cur.dist;

        if (d > dist[u]) continue;

        for (Edge* e = adj[u]; e != NULL; e = e->next) {
            int v = e->to;
            int w = e->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // remove if directed
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}