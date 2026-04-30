/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
in c*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V;                         // number of vertices
int adj[MAX][MAX];             // adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;

// push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS utility
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    // push after visiting all neighbors
    push(v);
}

// topological sort
void topoSort() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // print in reverse stack order
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int E, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // initialize
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    printf("Topological Order:\n");
    topoSort();

    return 0;
}