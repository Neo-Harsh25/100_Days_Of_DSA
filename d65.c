/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

// DFS with parent tracking
int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return 1;
            } else if (i != parent) {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

int main() {
    int n;

    scanf("%d", &n);

    // input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int hasCycle = 0;

    // handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}