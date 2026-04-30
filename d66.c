/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

int V;                      // number of vertices
int adj[MAX][MAX];          // adjacency matrix
bool visited[MAX];
bool recStack[MAX];

bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i))
                    return true;
            }
            else if (recStack[i]) {
                return true; // cycle found
            }
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

bool hasCycle() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    // initialize
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    // input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}