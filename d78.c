/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 100005

typedef struct {
    int node;
    int weight;
} Pair;

typedef struct {
    Pair arr[MAXN];
    int size;
} MinHeap;

void swap(Pair *a, Pair *b) {
    Pair t = *a;
    *a = *b;
    *b = t;
}

void push(MinHeap *h, int node, int weight) {
    h->arr[h->size].node = node;
    h->arr[h->size].weight = weight;
    int i = h->size;
    h->size++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent].weight > h->arr[i].weight) {
            swap(&h->arr[parent], &h->arr[i]);
            i = parent;
        } else break;
    }
}

Pair pop(MinHeap *h) {
    Pair top = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    int i = 0;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < h->size && h->arr[left].weight < h->arr[smallest].weight)
            smallest = left;
        if (right < h->size && h->arr[right].weight < h->arr[smallest].weight)
            smallest = right;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
    return top;
}

// adjacency list
typedef struct Edge {
    int to, weight;
    struct Edge *next;
} Edge;

Edge* adj[MAXN];

void addEdge(int u, int v, int w) {
    Edge* e1 = (Edge*)malloc(sizeof(Edge));
    e1->to = v; e1->weight = w; e1->next = adj[u];
    adj[u] = e1;

    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->to = u; e2->weight = w; e2->next = adj[v];
    adj[v] = e2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    bool visited[MAXN] = {false};
    MinHeap heap;
    heap.size = 0;

    long long mst_weight = 0;

    // start from node 1
    push(&heap, 1, 0);

    while (heap.size > 0) {
        Pair p = pop(&heap);
        int u = p.node;
        int w = p.weight;

        if (visited[u]) continue;

        visited[u] = true;
        mst_weight += w;

        Edge* temp = adj[u];
        while (temp) {
            if (!visited[temp->to]) {
                push(&heap, temp->to, temp->weight);
            }
            temp = temp->next;
        }
    }

    printf("%lld\n", mst_weight);
    return 0;
}