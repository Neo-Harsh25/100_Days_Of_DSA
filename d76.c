/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int visited[MAX];
int *adj[MAX];
int size[MAX];

void addEdge(int u, int v) {
    adj[u] = realloc(adj[u], (size[u] + 1) * sizeof(int));
    adj[u][size[u]++] = v;

    adj[v] = realloc(adj[v], (size[v] + 1) * sizeof(int));
    adj[v][size[v]++] = u;
}

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < size[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        size[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}